#This is "Guess the Number" Game
import random

print("Hello! What is your name?")
myName = input()
number = random.randint(1, 20) #여기서 1과 20을 정수로 썼기 때문에 
guessesTaken = 1

print("Well, " + myName + ".")
print("I am thinking of a number between 1 and 20.")
print("Can you guess the number?")

while guessesTaken < 6 :
    guessesTaken = guessesTaken + 1
    guess = input()
    guess = int(guess) #밑에서 number와 비교할 변수인 guess도 정수로 설정
    if guess > number :
        print("Your guess is too high.")
    if guess < number :
        print("Your guess is too low.")
    if guess == number :
        print("Good job, " + myName + "!")
        break

print("Oh, you have any chance to guess the number.")
number = str(number)
print("The answer is " + number + ".")
