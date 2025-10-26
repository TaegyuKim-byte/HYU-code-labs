
l_score = []
while True :
    score = input("Enter score! : ")
    if score == " " :
        break
    score = int(score)
    if score >= 0 and score <= 100 :
        l_score.append(score)

print("Total :", sum(l_score))
print("Avg : ",  sum(l_score)/len(l_score))
        
