import pandas as pd

# Load the Excel files
muslim_df = pd.read_excel("muslim_final.xlsx")
other_df = pd.read_excel("other_religion_final.xlsx")

# Keep only the 'text' column from both
muslim_text = muslim_df['text']
other_text = other_df['text']

# Combine and remove duplicates
combined_text = pd.concat([muslim_text, other_text]).drop_duplicates().reset_index(drop=True)

# Create final DataFrame with empty label column
final_df = pd.DataFrame({
    'text': combined_text,
    'label': ''
})

# Save to new Excel file
final_df.to_excel("banglish_final.xlsx", index=False)

print("banglish_final.xlsx has been created successfully.")
