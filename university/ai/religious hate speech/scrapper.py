from googleapiclient.discovery import build
import pandas as pd
import re
import time

API_KEY = "AIzaSyDRQBdPF3flYzZ-w2pg_g_5nek21h-6oUE"

# ------------------------
# Keywords for this project
# ------------------------
KEYWORDS = [
    "bangladesh politics",
    "islam debate bangla",
    "hindu muslim bangla",
    "bangla religious talk",
    "bangla news debate"
]

VIDEOS_PER_KEYWORD = 20

# ------------------------
# Banglish filter function
# ------------------------
def is_banglish(text):
    # Bengali unicode range = \u0980–\u09FF
    return not re.search(r'[\u0980-\u09FF]', text)

# ------------------------
# Search YouTube for videos
# ------------------------
def search_video_ids(keyword, api_key, max_results):
    youtube = build("youtube", "v3", developerKey=api_key)

    response = youtube.search().list(
        q=keyword,
        part="id",
        type="video",
        maxResults=max_results
    ).execute()

    video_ids = [item['id']['videoId'] for item in response['items']]
    return video_ids

# ------------------------
# Fetch comments for a video
# ------------------------
def get_comments(video_id, api_key):
    youtube = build("youtube", "v3", developerKey=api_key)

    comments = []
    next_page_token = None

    while True:
        response = youtube.commentThreads().list(
            part="snippet",
            videoId=video_id,
            maxResults=100,
            pageToken=next_page_token,
            textFormat="plainText"
        ).execute()

        for item in response["items"]:
            snippet = item["snippet"]["topLevelComment"]["snippet"]
            text = snippet["textDisplay"]

            # Keep only Banglish comments
            if is_banglish(text):
                comments.append({
                    "video_id": video_id,
                    "comment_id": item["id"],
                    "author": snippet.get("authorDisplayName", ""),
                    "comment": text,
                    "published_at": snippet.get("publishedAt", ""),
                    "like_count": snippet.get("likeCount", 0)
                })

        next_page_token = response.get("nextPageToken")
        if not next_page_token:
            break

    return comments

# ------------------------
# Main Collection Process
# ------------------------
all_comments = []

for kw in KEYWORDS:
    print(f"\nSearching for keyword: {kw}")
    video_ids = search_video_ids(kw, API_KEY, VIDEOS_PER_KEYWORD)

    print(f"Found {len(video_ids)} videos")

    for vid in video_ids:
        print(f"   Scraping comments from video: {vid}")
        try:
            comments = get_comments(vid, API_KEY)
            all_comments.extend(comments)
            time.sleep(1)  # avoid API rate limits
        except Exception as e:
            print(f"Error fetching video {vid}: {e}")

# ------------------------
# Save to Excel
# ------------------------
df = pd.DataFrame(all_comments)
output_file = "banglish_comments_by_keywords.xlsx"
df.to_excel(output_file, index=False)

print("\nDONE!")
print(f"Saved {len(df)} Banglish comments to: {output_file}")
