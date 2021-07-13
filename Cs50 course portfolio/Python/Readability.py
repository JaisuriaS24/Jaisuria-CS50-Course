from cs50 import get_string

Text = get_string("Text: ")  # This will prompt the user to type a sentence.


def index(text):
    letters = count_letters(text)
    sentences = count_sentences(text)
    words = count_words(text)  # This part is programmed to assign the values
    

# To count the number of letters in the text
letters = 0
for i in Text:
    if (i >= "a" and i <= 'z') or (i >= "A" and i <= "Z"):
        letters += 1
        
# To count the number of sentences
sentences = 0
for i in Text:
    if i == "." or i == "!" or i == "?":
        sentences += 1
        
# To count the number of words
words = 1
for i in Text:
    if (i == " "):
        words += 1


x = (sentences * (100/words))
y = (letters * (100/words))


index = round(((0.0588 * y) - (0.296 * x) - 15.8))

if index < 1:
    print("Before Grade 1")
    
elif index > 16:
    print("Grade 16+\n")
    
else:
    print(f"Grade {index}")