playAgain = True
while playAgain :
    print("some logic here...")
    print("Do you want to play again? (yes or no)")

    yesno = input()

    if yesno != "yes" and yesno != "no" :
        print("Do you want to play again? (yes or no)")
        yesno = input()

    if yesno == "no" :
        break
