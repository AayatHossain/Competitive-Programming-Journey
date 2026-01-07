import pandas as pd

# ====== INPUT FILES ======
facebook_file = "facebook.xlsx"
youtube_file = "youtube.xlsx"

# ====== READ EXCELS ======
df_fb = pd.read_excel(facebook_file)
df_yt = pd.read_excel(youtube_file)

# ====== NORMALIZE COLUMN NAMES ======
for df in (df_fb, df_yt):
    df.columns = df.columns.str.strip().str.lower()

# ====== PREPARE FACEBOOK DATA ======
df_fb["platform"] = "facebook"
df_fb["original_text"] = df_fb["text"]
df_fb["english_translation"] = ""
df_fb["label"] = ""

df_fb = df_fb[["platform", "language", "original_text", "english_translation", "label"]]

# ====== PREPARE YOUTUBE DATA ======
df_yt["platform"] = "youtube"
df_yt["original_text"] = df_yt["text"]
df_yt["english_translation"] = ""
df_yt["label"] = ""

df_yt = df_yt[["platform", "language", "original_text", "english_translation", "label"]]

# ====== MERGE ======
dataset = pd.concat([df_fb, df_yt], ignore_index=True)

# ====== ADD ID COLUMN (1…N) ======
dataset.insert(0, "id", range(1, len(dataset) + 1))

# ====== SAVE TO EXCEL ======
dataset.to_excel("dataset.xlsx", index=False)

print("Done! dataset.xlsx created successfully.")
