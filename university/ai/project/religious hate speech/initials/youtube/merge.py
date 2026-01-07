import pandas as pd

# ====== FILE NAMES ======
bangla_file = "bangla_final.xlsx"
banglish_file = "banglish_final.xlsx"
english_file = "english_final.xlsx"

# ====== READ THE EXCEL FILES ======
df_bangla = pd.read_excel(bangla_file)
df_banglish = pd.read_excel(banglish_file)
df_english = pd.read_excel(english_file)

# ====== NORMALIZE COLUMN NAMES (important!) ======
for df in (df_bangla, df_banglish, df_english):
    df.columns = df.columns.str.strip().str.lower()

# ====== RENAME TEXT COLUMN IF NEEDED ======
# (uncomment & adjust if your text column has another name)
# df_bangla.rename(columns={"comment": "text"}, inplace=True)

# ====== ASSIGN LANGUAGE ======
df_bangla["language"] = "bangla"
df_banglish["language"] = "banglish"
df_english["language"] = "english"

# ====== KEEP ONLY REQUIRED COLUMNS ======
df_bangla = df_bangla[["text", "language"]]
df_banglish = df_banglish[["text", "language"]]
df_english = df_english[["text", "language"]]

# ====== MERGE ======
youtube_df = pd.concat([df_bangla, df_banglish, df_english], ignore_index=True)

# ====== SAVE TO EXCEL ======
youtube_df.to_excel("youtube.xlsx", index=False)

print("Done! youtube.xlsx created successfully.")
