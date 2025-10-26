playAgain = True

while playAgain :
    print("some logic here...")

    yesno = ""

    while yesno != "yes" and yesno != "no" :
        print("Do you want to play it again? (yes or no)")
        yesno = input()


    if yesno == "yes" :
        playAgain = True
    else :
        playAgain = False
