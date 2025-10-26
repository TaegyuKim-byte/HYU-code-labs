import random, time

print("Let's flip the coin!")
coinflip = random.randint(1, 2)

time.sleep(3)

if coinflip == 1 :
    print("(백원)")
    
else :
    print("(100)")
