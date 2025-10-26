import random

def pickRandomWord(words) :
    idx = random.randint(0, len(words)-1)
    word = words[idx]
    return word

words = '''ant baboon badger bat bear beaver camel cat clam cougar coyote crew deer dog donkey duck eagle
ferret fox frog goat goose hawk lion lizard llama mole monkey moose mouse mule newt otter owl
panda parrot pigeon rabbit ram rat raven rhino salmon
seal shark sheep skunk sloth snake spider stork swan tiger toad trout turkey turtle whale wolf wombat zebra'''.split() 


def removeRedundantCharacter(secretWord) :
    letters = []
    for letter in secretWord :
        if letter not in letters :
            letters.append(letter.lower())
    return letters

#word는 랜덤 단어 // letters 는 겹치는거 제외시킨 리스트(앞으로 맞
                                                       #춰야 할 것들)-> 완성 

playAgain = True
while playAgain :

    word = pickRandomWord(words)
    secretWord = word
    letters = removeRedundantCharacter(secretWord)

    #print(word, letters)  -> 정답 확인용 
    
    print("Guess my word!")
    guesses = ""

    while len(letters) > 0 :
        guess = input()
        guess = guess.lower()

        if guess in guesses :
            print("You've already typed the letter.")

        elif guess in letters :
            guesses = guesses + guess
            pos = letters.index(guess)
            del letters[pos]
            print("You found a letter in the word.")

        else :
            print("You missed a letter in the word.")


        print("Your collection :" , end = "")
        
        for letter in word :
            if letter in guesses :
                print(letter, end = "")

            if letter not in guesses :
                print("_", end = "")

        print()

    
    print("Do you want to play again? (yes or no)")
    answer = input()
    while answer != "yes" and answer != "no" :
        print("Do you want to play again? (yes or no)")
        answer = input()
    if answer == "yes" :
        playAgain = True
    else :
        playAgain = False
    
    
