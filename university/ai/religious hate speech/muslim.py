from googleapiclient.discovery import build
import pandas as pd
import re
import time
from googleapiclient.errors import HttpError

API_KEY = "AIzaSyDRQBdPF3flYzZ-w2pg_g_5nek21h-6oUE"

# -------------------------------------------------
# Muslim-related keywords (10)
# -------------------------------------------------
MUSLIM_KEYWORDS = [
    "islam debate bangla",
    "islam vs hindu debate bangla",
    "islam vs christian debate bangla",
    "islam vs buddhism debate bangla",
    "quran criticism bangla",
    "hadith debate bangla",
    "political islam bangla",
    "islami alochona bangla",
    "bangla islam reaction",
    "bangladesh islam news debate"
]

VIDEOS_PER_KEYWORD = 10
MAX_COMMENTS_PER_VIDEO = 400
MAX_REPLIES_PER_COMMENT = 5

# -------------------------------------------------
# Banglish filter
# -------------------------------------------------
def is_banglish(text):
    return not re.search(r'[\u0980-\u09FF]', text)

# -------------------------------------------------
# YouTube API client
# -------------------------------------------------
youtube = build("youtube", "v3", developerKey=API_KEY)

# -------------------------------------------------
# Search videos by view count
# -------------------------------------------------
def search_video_ids(keyword):
    try:
        response = youtube.search().list(
            q=keyword,
            part="id",
            type="video",
            maxResults=VIDEOS_PER_KEYWORD,
            order="viewCount"
        ).execute()
        return [item["id"]["videoId"] for item in response["items"]]
    except HttpError as e:
        print(f"  Failed to search videos for keyword: {keyword}")
        return []

# -------------------------------------------------
# Fetch limited replies (safe)
# -------------------------------------------------
def get_replies(parent_id, video_id):
    replies = []
    next_page_token = None

    while True:
        try:
            response = youtube.comments().list(
                part="snippet",
                parentId=parent_id,
                maxResults=MAX_REPLIES_PER_COMMENT,
                pageToken=next_page_token,
                textFormat="plainText"
            ).execute()
        except HttpError:
            break

        for item in response["items"]:
            snippet = item["snippet"]
            text = snippet["textDisplay"]

            if is_banglish(text):
                replies.append({
                    "video_id": video_id,
                    "comment_id": item["id"],
                    "parent_id": parent_id,
                    "is_reply": 1,
                    "author": snippet.get("authorDisplayName", ""),
                    "comment": text,
                    "published_at": snippet.get("publishedAt", ""),
                    "like_count": snippet.get("likeCount", 0)
                })

            if len(replies) >= MAX_REPLIES_PER_COMMENT:
                return replies

        next_page_token = response.get("nextPageToken")
        if not next_page_token:
            break

    return replies

# -------------------------------------------------
# Main scraping logic (SAFE)
# -------------------------------------------------
all_comments = []

for keyword in MUSLIM_KEYWORDS:
    print(f"\nSearching videos for keyword: {keyword}")
    video_ids = search_video_ids(keyword)

    for video_id in video_ids:
        print(f"  Scraping video: {video_id}")
        video_comment_count = 0
        next_page_token = None

        while video_comment_count < MAX_COMMENTS_PER_VIDEO:
            try:
                response = youtube.commentThreads().list(
                    part="snippet",
                    videoId=video_id,
                    maxResults=100,
                    pageToken=next_page_token,
                    textFormat="plainText"
                ).execute()
            except HttpError:
                print(f"    Skipping video {video_id} (comments disabled or unavailable)")
                break

            for item in response["items"]:
                if video_comment_count >= MAX_COMMENTS_PER_VIDEO:
                    break

                snippet = item["snippet"]["topLevelComment"]["snippet"]
                text = snippet["textDisplay"]
                parent_id = item["snippet"]["topLevelComment"]["id"]

                if is_banglish(text):
                    all_comments.append({
                        "video_id": video_id,
                        "comment_id": parent_id,
                        "parent_id": None,
                        "is_reply": 0,
                        "author": snippet.get("authorDisplayName", ""),
                        "comment": text,
                        "published_at": snippet.get("publishedAt", ""),
                        "like_count": snippet.get("likeCount", 0)
                    })
                    video_comment_count += 1

                # Fetch limited replies
                if (
                    item["snippet"].get("totalReplyCount", 0) > 0
                    and video_comment_count < MAX_COMMENTS_PER_VIDEO
                ):
                    replies = get_replies(parent_id, video_id)
                    for r in replies:
                        if video_comment_count >= MAX_COMMENTS_PER_VIDEO:
                            break
                        all_comments.append(r)
                        video_comment_count += 1

            next_page_token = response.get("nextPageToken")
            if not next_page_token:
                break

            time.sleep(0.2)

# -------------------------------------------------
# Save to Excel
# -------------------------------------------------
df = pd.DataFrame(all_comments)
output_file = "muslim_comments_fast.xlsx"
df.to_excel(output_file, index=False)

print("\nDONE")
print(f"Saved {len(df)} comments to {output_file}")
