total = 0
count = 0

while True :
    score = input("Enter Score: ")
    if score == "":
        break
    total = total + int(score)
    count = count + 1

print("total: " + str(total))
print("Avg. :" + str(total/count))
