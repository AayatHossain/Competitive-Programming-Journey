import pandas as pd

# === 1. ENTER YOUR FILE NAME HERE ===
input_file = "english_comments.xlsx"      # example: dataset.xlsx
output_file = "english.xlsx"

# === 2. LOAD EXCEL FILE ===
df = pd.read_excel(input_file)



# === 4. ADD NEW COLUMN ===
df["language"] = "english"

# === 5. SAVE NEW EXCEL FILE ===
df.to_excel(output_file, index=False)

print(f"Done! New file saved as: {output_file}")
