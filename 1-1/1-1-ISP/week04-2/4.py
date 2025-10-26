



 # _tt__로 출력
word = "otter"
guesses = ["t"] #Guesses : 내가 입력한 철자들 

def displayLetters(word, guesses) :
    for letter in word :
        if letter in guesses :
            print(letter, end = "")

        if letter not in guesses :
            print("_", end = "")


word = "otter"
guesses = ["t"]
displayLetters(word, guesses)





