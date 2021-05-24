from cs50 import get_string

text = get_string("Text: ")

count_letters = 0
count_words = 1
count_sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        count_letters += 1
    if text[i] == ' ':
        count_words += 1
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        count_sentences += 1

l = (count_letters / count_words) * 100
s = (count_sentences / count_words) * 100

grade = round((0.0588 * l) - (0.296 * s) - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")