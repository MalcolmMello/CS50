from cs50 import get_string

text = get_string("Write your text: ")

letters = 0
words = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters+=1

    if i == ' ':
        words+=1

    if i == '.' or i == '!' or i == '?':
        sentences+=1

L = (letters/words) * 100
S = (sentences/words) * 100

index = round((0.0588 * L - 0.296 * S - 15.8), ndigits = 2)

if(index < 1):
    print("Before Grade 1\n")

elif(index >= 16):
    print("Grade 16+\n")

else:
    print(f"Grade {round(index)}")