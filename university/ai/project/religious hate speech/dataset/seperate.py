import pandas as pd

# Read the Excel file
df = pd.read_excel("dataset.xlsx")

# Normalize the language column
df["language"] = df["language"].astype(str).str.strip().str.lower()

# Function to save rows for a given language
def save_texts(lang_name):
    subset = df[df["language"] == lang_name][["original_text", "language"]]
    if not subset.empty:
        subset.to_excel(f"{lang_name}.xlsx", index=False)
        print(f"Saved {len(subset)} rows to {lang_name}.xlsx")
    else:
        print(f"No rows found for language: {lang_name}")

# Create the 3 files
save_texts("bangla")
save_texts("banglish")
save_texts("english")
