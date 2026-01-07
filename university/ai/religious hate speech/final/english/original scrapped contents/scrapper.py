from googleapiclient.discovery import build
from googleapiclient.errors import HttpError
import pandas as pd
import re
import time
from langdetect import detect, DetectorFactory

# Make language detection deterministic
DetectorFactory.seed = 0

# ================================
# CONFIG
# ================================
API_KEY = "AIzaSyDRQBdPF3flYzZ-w2pg_g_5nek21h-6oUE"

TARGET_VIDEOS_PER_RELIGION = 100
MAX_COMMENTS_PER_VIDEO = 70
MAX_TOP_COMMENTS_PER_VIDEO = 60
MAX_REPLIES_PER_VIDEO = 15
PER_RELIGION_MAX_COMMENTS = 5000
SEARCH_BATCH = 50


# ================================
# TRUE English detection
# ================================
def is_english_comment(text,
                       min_chars=15,
                       min_words=3):

    if not text:
        return False

    text = text.replace("\n", " ").strip()

    if len(text) < min_chars:
        return False

    if len(text.split()) < min_words:
        return False

    try:
        lang = detect(text)
    except:
        return False

    return lang == "en"


# ================================
# Religion keyword lists (UNCHANGED)
# ================================
ISLAM_KEYWORDS = [
    "islam debate bangla",
    "islam vs hindu debate bangla",
    "islam vs christian debate bangla",
    "islam vs buddhism debate bangla",
    "quran criticism bangla",
    "hadith discussion bangla",
    "islamic history debate bangla",
    "political islam discussion bangla",
    "islam lecture reaction bangla",
    "bangladesh islam news debate"
]

HINDU_KEYWORDS = [
    "hindu dharma debate bangla",
    "gita discussion bangla",
    "hinduism vs islam debate bangla",
    "hinduism vs christianity debate bangla",
    "hinduism vs buddhism debate bangla",
    "puran criticism bangla",
    "hindu religious talk bangla",
    "hindu philosophy debate bangla",
    "hindu lecture reaction bangla",
    "bangladesh hindu news debate"
]

CHRISTIAN_KEYWORDS = [
    "christianity debate bangla",
    "bible criticism bangla",
    "christian vs islam debate bangla",
    "christian vs hindu debate bangla",
    "christian vs buddhism debate bangla",
    "jesus discussion bangla",
    "church talk bangla",
    "christianity history debate bangla",
    "christian sermon reaction bangla",
    "bangladesh christian news debate"
]

BUDDHIST_KEYWORDS = [
    "buddhism debate bangla",
    "buddha discussion bangla",
    "buddhism vs islam debate bangla",
    "buddhism vs hindu debate bangla",
    "buddhism vs christianity debate bangla",
    "tripitaka criticism bangla",
    "buddhist philosophy bangla",
    "buddhist religion talk bangla",
    "buddhist lecture reaction bangla",
    "bangladesh buddhist news debate"
]

RELIGION_KEYWORDS = {
    "Islam": ISLAM_KEYWORDS,
    "Hinduism": HINDU_KEYWORDS,
    "Christianity": CHRISTIAN_KEYWORDS,
    "Buddhism": BUDDHIST_KEYWORDS,
}

# ================================
# YouTube API client
# ================================
youtube = build("youtube", "v3", developerKey=API_KEY)


# ================================
# Helpers
# ================================
def search_videos_for_religion(keywords, target):
    video_ids = set()
    for keyword in keywords:
        next_page = None
        while len(video_ids) < target:
            try:
                response = youtube.search().list(
                    q=keyword,
                    part="id",
                    type="video",
                    order="viewCount",
                    maxResults=SEARCH_BATCH,
                    pageToken=next_page,
                    regionCode="BD",          # Bangladesh-focused videos
                    relevanceLanguage="en"    # Prefer English
                ).execute()
            except HttpError:
                break

            for item in response.get("items", []):
                video_ids.add(item["id"]["videoId"])
                if len(video_ids) >= target:
                    break

            next_page = response.get("nextPageToken")
            if not next_page:
                break

            time.sleep(0.2)

        if len(video_ids) >= target:
            break

    return list(video_ids)


def get_replies(parent_id, video_id, religion, remaining):
    replies = []
    next_page = None

    while remaining > 0:
        try:
            response = youtube.comments().list(
                part="snippet",
                parentId=parent_id,
                maxResults=min(remaining, 100),
                pageToken=next_page,
                textFormat="plainText"
            ).execute()
        except HttpError:
            break

        for item in response.get("items", []):
            s = item["snippet"]
            text = s.get("textDisplay", "")

            if is_english_comment(text):
                replies.append({
                    "religion": religion,
                    "video_id": video_id,
                    "comment_id": item["id"],
                    "parent_id": parent_id,
                    "is_reply": 1,
                    "author": s.get("authorDisplayName", ""),
                    "comment": text,
                    "published_at": s.get("publishedAt", ""),
                    "like_count": s.get("likeCount", 0)
                })
                remaining -= 1
                if remaining <= 0:
                    break

        next_page = response.get("nextPageToken")
        if not next_page:
            break

    return replies


# ================================
# Main scraping loop
# ================================
all_comments = []
seen = set()

for religion, keywords in RELIGION_KEYWORDS.items():
    print(f"\n=== Collecting for: {religion} ===")

    religion_count = 0
    video_ids = search_videos_for_religion(
        keywords,
        TARGET_VIDEOS_PER_RELIGION
    )

    print(f"Found {len(video_ids)} videos")

    for idx, vid in enumerate(video_ids, 1):
        if religion_count >= PER_RELIGION_MAX_COMMENTS:
            break

        print(f"[{religion}] Video {idx}/{len(video_ids)}: {vid}")

        collected_this_video = 0
        replies_taken = 0
        next_page = None

        while (
            collected_this_video < MAX_COMMENTS_PER_VIDEO and
            religion_count < PER_RELIGION_MAX_COMMENTS
        ):
            try:
                response = youtube.commentThreads().list(
                    part="snippet",
                    videoId=vid,
                    maxResults=100,
                    pageToken=next_page,
                    textFormat="plainText"
                ).execute()
            except HttpError:
                print(f"  Skipping (comments disabled): {vid}")
                break

            for item in response.get("items", []):
                if (
                    collected_this_video >= MAX_COMMENTS_PER_VIDEO or
                    religion_count >= PER_RELIGION_MAX_COMMENTS
                ):
                    break

                top = item["snippet"]["topLevelComment"]["snippet"]
                text = top.get("textDisplay", "")
                cid = item["snippet"]["topLevelComment"]["id"]

                norm = (vid, cid, text.strip().lower())
                if norm in seen:
                    continue

                if is_english_comment(text):
                    all_comments.append({
                        "religion": religion,
                        "video_id": vid,
                        "comment_id": cid,
                        "parent_id": None,
                        "is_reply": 0,
                        "author": top.get("authorDisplayName", ""),
                        "comment": text,
                        "published_at": top.get("publishedAt", ""),
                        "like_count": top.get("likeCount", 0)
                    })
                    seen.add(norm)
                    collected_this_video += 1
                    religion_count += 1

                if (
                    replies_taken < MAX_REPLIES_PER_VIDEO and
                    collected_this_video < MAX_COMMENTS_PER_VIDEO
                ):
                    remaining = min(
                        MAX_REPLIES_PER_VIDEO - replies_taken,
                        MAX_COMMENTS_PER_VIDEO - collected_this_video
                    )

                    if item["snippet"].get("totalReplyCount", 0) > 0 and remaining > 0:
                        replies = get_replies(
                            parent_id=cid,
                            video_id=vid,
                            religion=religion,
                            remaining=remaining
                        )

                        all_comments.extend(replies)
                        replies_taken += len(replies)
                        collected_this_video += len(replies)
                        religion_count += len(replies)

            next_page = response.get("nextPageToken")
            if not next_page:
                break

            time.sleep(0.2)

    print(f"[{religion}] collected {religion_count} comments")

# ================================
# Save
# ================================
df = pd.DataFrame(all_comments)
df.to_excel("religion_english_comments_bd.xlsx", index=False)

print("\nDONE")
print(f"Saved {len(df)} comments total")
