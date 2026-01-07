import pandas as pd

# ====== FILE NAMES ======
bangla_file = "bangla.xlsx"
banglish_file = "banglish.xlsx"
english_file = "english.xlsx"

# ====== READ THE EXCEL FILES ======
df_bangla = pd.read_excel(bangla_file)
df_banglish = pd.read_excel(banglish_file)
df_english = pd.read_excel(english_file)

# ====== COMBINE THEM ======
facebook_df = pd.concat([df_bangla, df_banglish, df_english], ignore_index=True)

# ====== KEEP ONLY REQUIRED COLUMNS ======
facebook_df = facebook_df[["text", "language"]]

# ====== SAVE TO EXCEL ======
facebook_df.to_excel("facebook.xlsx", index=False)

print("Done! facebook.xlsx created successfully.")
