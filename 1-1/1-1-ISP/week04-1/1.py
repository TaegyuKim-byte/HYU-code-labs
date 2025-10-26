while True :
    print("Do you want to play again?")
    answer = ""
    while True :
        answer = input()
        if answer in ["yes", "no", "y", "n"] :
            break

    if answer in ["no", "n"] :
        break
