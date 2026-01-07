import pandas as pd

# Load the merged file
df = pd.read_excel("facebook.xlsx")

# Ensure we're only checking the 'text' column
texts = df["text"]

total_rows = len(texts)
unique_rows = texts.nunique()
duplicate_count = total_rows - unique_rows

print(f"Total rows: {total_rows}")
print(f"Unique texts: {unique_rows}")
print(f"Duplicate texts found: {duplicate_count}")
