from googleapiclient.discovery import build
from googleapiclient.errors import HttpError
import pandas as pd
import fasttext
import time

# ================================
# CONFIG
# ================================
API_KEY = "AIzaSyDRQBdPF3flYzZ-w2pg_g_5nek21h-6oUE"

TARGET_VIDEOS_PER_RELIGION = 50
MAX_TOP_COMMENTS_PER_VIDEO = 240
MAX_REPLIES_PER_VIDEO = 10
PER_RELIGION_MAX_COMMENTS = 12000
SEARCH_BATCH = 50

MIN_WORDS = 3      # <-- ignore short comments
THRESHOLD = 1.00   # <-- prob must be 1.0
MODEL_PATH = "model_banglishV2.bin"
BANGLISH_LABEL = "__label__banglish"

# ================================
# fastText
# ================================
model = fasttext.load_model(MODEL_PATH)

def is_banglish_fasttext(text, threshold=THRESHOLD):
    text = (text or "").replace("\n", " ").strip()
    if not text or len(text.split()) < MIN_WORDS:
        return False
    label, prob = model.predict(text, k=1)
    return label[0] == BANGLISH_LABEL and prob[0] >= threshold


# ================================
# Religion keyword lists (NO ISLAM)
# ================================
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
                    maxResults=SEARCH_BATCH,
                    order="viewCount",
                    pageToken=next_page
                ).execute()
            except HttpError:
                break

            for item in response.get("items", []):
                vid = item["id"]["videoId"]
                video_ids.add(vid)
                if len(video_ids) >= target:
                    break

            next_page = response.get("nextPageToken")
            if not next_page:
                break

            time.sleep(0.2)

        if len(video_ids) >= target:
            break

    return list(video_ids)


# ================================
# Main scraping loop
# ================================
all_comments = []
seen_texts = set()

for religion, keywords in RELIGION_KEYWORDS.items():
    print(f"\n===============================")
    print(f" Collecting for: {religion}")
    print(f"===============================")

    religion_count = 0
    video_ids = search_videos_for_religion(keywords, TARGET_VIDEOS_PER_RELIGION)
    print(f"Found {len(video_ids)} videos")

    for idx, video_id in enumerate(video_ids, 1):
        if religion_count >= PER_RELIGION_MAX_COMMENTS:
            break

        print(f"[{religion}] Video {idx}/{len(video_ids)}: {video_id}")

        top_comments_taken = 0
        next_page_token = None

        while (
            top_comments_taken < MAX_TOP_COMMENTS_PER_VIDEO
            and religion_count < PER_RELIGION_MAX_COMMENTS
        ):
            try:
                response = youtube.commentThreads().list(
                    part="snippet",
                    videoId=video_id,
                    maxResults=100,
                    pageToken=next_page_token,
                    textFormat="plainText"
                ).execute()
            except HttpError:
                break

            for item in response.get("items", []):

                if (
                    top_comments_taken >= MAX_TOP_COMMENTS_PER_VIDEO
                    or religion_count >= PER_RELIGION_MAX_COMMENTS
                ):
                    break

                top = item["snippet"]["topLevelComment"]["snippet"]
                text = (top.get("textDisplay", "") or "").replace("\n", " ").strip()

                if not text or len(text.split()) < MIN_WORDS:
                    continue

                if text.lower() in seen_texts:
                    continue

                if is_banglish_fasttext(text):
                    all_comments.append({
                        "video_id": video_id,   # <-- ADDED
                        "text": text,
                        "label": ""             # <-- still blank
                    })
                    seen_texts.add(text.lower())
                    top_comments_taken += 1
                    religion_count += 1

            next_page_token = response.get("nextPageToken")
            if not next_page_token:
                break

            time.sleep(0.2)

    print(f"[{religion}] collected {religion_count} comments")

# ================================
# Save WITH video_id
# ================================
df = pd.DataFrame(all_comments, columns=["video_id", "text", "label"])
df.to_excel("other_religion.xlsx", index=False)

print("\nDONE")
print(f"Saved {len(df)} comments total to other_religion.xlsx")
