while True :
    print("Enter the score!(0~100)")
    score = input()
    numberOfScore = 0
    numberOfScore += 1
    scoreSum = ""
    scoreSum = scoreSum + score
    if score == " " :
        break

print(" Total : " + scoreSum )
print("Avg : " + scoreSum/numberOfScore + scoreSum%numberOfScore)
    
    
