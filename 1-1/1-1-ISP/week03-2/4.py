import random
import time

def validInput(prompt, option1, option2):
    user_input = ""
    while user_input != option1 and user_input != option2:
        user_input = input(prompt).lower()
    return user_input

def chosenCave() :
    return validInput("Which cave do you want to go into? (1 or 2)", "1", "2")

def displayIntro() :
    print("You are in a land full of dragons. in front of you...")
    time.sleep(5)
    print("you see two caves. in one cave, the dragon is friendly.")
    time.sleep(5)
    print("and will share his treasure with you. The other dragon")
    time.sleep(5)
    print("is greedly and hungry. and will eat you on sight")

def askPlayAgain() :
    return validInput("do you want to play again? (yes or no)", "yes", "no")

playAgain = True

while playAgain :

    displayIntro()

    cave = random.randint(1, 2)
    chosen = chosenCave()

    print("You approach the cave...")
    time.sleep(3)
    print("It is dark and sponky.")
    time.sleep(3)
    print("A large dragon jumps our in front of you!")
    time.sleep(3)
    print("And...")
    time.sleep(3)
    
    cave = str(cave)
    if cave == chosen :
        print("You died.")
    else :
        print("You get rich!")

    playAgain = askPlayAgain() == "yes"
