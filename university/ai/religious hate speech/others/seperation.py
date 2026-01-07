import pandas as pd
import re

# ==== SETTINGS ====
INPUT_FILE = "facebook.xlsx"     # <-- change this to your file name
TEXT_COLUMN_NAME = "text"        # <-- change to your column name

# ==== REGEX HELPERS ====
bengali_re = re.compile(r'[\u0980-\u09FF]')
word_re = re.compile(r"[A-Za-z]+")

# ==== SMALL ENGLISH DICTIONARY ====
ENGLISH_WORDS = set("""
a about after again all am an and are as at be because been before being
but by can come could did do does doing down each even for from get give go
had has have he her here him his how i if in into is it its just like make
me more most my no not now of on one only or our out over said see she so some
than that the their them then there they this time to two up us use very want
was way we well were what when which who will with would you your yes love like
hello hi thank thanks please good great bad fine ok okay really today tomorrow
""".split())


def classify_text(text):
    """Classify into bangla / english / banglish"""
    if not isinstance(text, str):
        return "unknown"

    text = text.strip()

    # 1️⃣ Any Bangla script -> Bangla
    if bengali_re.search(text):
        return "bangla"

    # 2️⃣ Extract English-looking words
    words = word_re.findall(text.lower())

    if not words:
        return "banglish"

    english_matches = sum(1 for w in words if w in ENGLISH_WORDS)
    ratio = english_matches / len(words)

    # 3️⃣ Only very clean English counts
    if ratio >= 0.8:
        return "english"

    # 4️⃣ Otherwise -> Banglish
    return "banglish"


def main():
    df = pd.read_excel(INPUT_FILE)

    if TEXT_COLUMN_NAME not in df.columns:
        print(f"Column '{TEXT_COLUMN_NAME}' not found. Available columns are:")
        print(list(df.columns))
        return

    df["category"] = df[TEXT_COLUMN_NAME].apply(classify_text)

    bangla_df = df[df["category"] == "bangla"]
    english_df = df[df["category"] == "english"]
    banglish_df = df[df["category"] == "banglish"]

    bangla_df.to_excel("bangla.xlsx", index=False)
    english_df.to_excel("english.xlsx", index=False)
    banglish_df.to_excel("banglish.xlsx", index=False)

    print("Finished!")
    print(f"Bangla rows:   {len(bangla_df)}")
    print(f"English rows:  {len(english_df)}")
    print(f"Banglish rows: {len(banglish_df)}")


if __name__ == "__main__":
    main()
