import random
num1 = random.randint(2,9)
num2 = random.randint(2,9)
print(str(num1) + " x " + str(num2) + " = ?")
ans = int(input())
if ans == num1 * num2 :
    print("정답!")
if ans != num1 * num2 :
    print("땡!")




