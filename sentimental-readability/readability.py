from cs50 import get_string

def count_letters(text):
    letra = 0
    for contador in text:
        if(contador.isalpha()):
            letra += 1
        else:
            continue
    return letra

def count_word(text):
    word=1
    c = ' '
    for cont in range(0,len(text)):
        if(text[cont]==c):
            word += 1
        else:
            continue
    return word

def count_sentence(text):
    sentence = 0
    for cont in range(0,len(text)):
        if((text[cont]=='.') or (text[cont]=='?') or (text[cont]=='!')):
            sentence += 1
        else:
            continue
    return sentence

text = get_string("Text: ")
letra = count_letters(text)
word = count_word(text)
sentence = count_sentence(text)
#print("O número de letras = %d" % letra)
#print("O número de palavras = %d" % word)
#print("O número de sentenças = %d" % sentence)
L = (letra*100)/word
S = (sentence*100)/word
index = 0.0588 * L - 0.296 * S - 15.8
if(index<1):
    print("Before Grade: 1")
elif(index>16):
    print("Grade: 16+")
else:
    print("Grade: %d"%round(index))