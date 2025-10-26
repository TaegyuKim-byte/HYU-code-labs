playAgain = True
import random


def inputYN() :
    yesno = ""
    while yesno != "yes" and yesno != "no" :
        print("Do you want to play again? (yes or no)")
        yesno = input()
    return yesno

    
    
while playAgain :
    coin = random.randint(1, 2)
    print("Let's flip the coin!")
    if coin == 1:
        print("        _.-'~~`~~'-._")
        print("     .'`  1  9  9  9 `'.")
        print("    /                   \\")
        print("  /`  /     000     000  `\\")
        print(" ;   /1   00   00 00   00  ;")
        print(";   111   0     0 0     0   ;")
        print("|     1   0     0 0     0   |")
        print("|     1   0     0 0     0   |")
        print(";     1   0     0 0     0   ;")
        print(" ;    1   00   00 00   00  ;")
        print("  \ 11111   000     000   /")
        print("   `\                   /`")
        print("     '._             _.'")
        print("        `'-..,,,..-'`")
    else :
        print("        _.-'~~`~~'-._")
        print("     .'`             `'.")
        print("    /       jJL\        \\")
        print("  /    @@@jJLjJJJL@@     `\\")
        print(" ;    @@@jJ===-L@@@@@      ;")
        print(";        jJ - -  L          ;")
        print("|        JJ  |   X          |")
        print("|        JJ ---  X          |")
        print(";        J|\    /|          ;")
        print(" ;       /  |  |  \        ;")
        print("  \     |          |      /")
        print("   `\\ /             \   /`")
        print("     '._             _.'")
        print("        `'-..,,,..-'`")
        
    yesno = inputYN()
    if yesno == "no" :
        playAgain = False

    
    
        
        
    
