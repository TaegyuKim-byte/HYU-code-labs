def removeRedundantCharacter(secretWord) :
    letters = []
    for letter in secretWord :
        if letter not in letters :
            letters.append(letter)
    return letters

secretWord = "otter"
letters = removeRedundantCharacter(secretWord)
print(letters)
    


