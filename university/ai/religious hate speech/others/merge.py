import pandas as pd

# List of input Excel files (add the correct extension if needed)
files = ["rahat.xlsx", "rahat_2.xlsx", "roman.xlsx", "sarawer.xlsx"]

dfs = []

for f in files:
    df = pd.read_excel(f, usecols=["text"])  # read only the 'text' column
    dfs.append(df)

# Merge all dataframes
combined = pd.concat(dfs, ignore_index=True)

# Remove duplicate text values
combined = combined.drop_duplicates(subset=["text"])

# Save to a new Excel file
combined.to_excel("facebook.xlsx", index=False)

print("Done! Saved as facebook.xlsx")
