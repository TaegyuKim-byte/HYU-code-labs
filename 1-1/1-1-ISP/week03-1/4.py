import time, random
playAgain = True

while playAgain :
    print("Let's flip the coin!")
    coin = random.randint(1, 2)

    time.sleep(3)

    if coin == 1 :
        print("(백원)")
    else :
        print("(100)")

    print("Do you want to play again? (yes or no)")

    yesno = input()

     
    while yesno != "yes" and yesno != "no" :
        print("Do you want to play again? (yes or no)")
        yesno = input()

    if yesno == "yes" :
        playAgain = True
    else :
        playAgain = False

    

    
    
