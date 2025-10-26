def divide(dividend, divisor) :
    quotient = dividend // divisor #// : 몫만 , / : 나머지 없이 나누기(소수)
    remainder = dividend % divisor
    return quotient, remainder


print("나눠지는 수 : " , end = "")
dividend = input()
print("나눌 수 : ", end = "")
divisor = input()

dividend = int(dividend)
divisor = int(divisor)

quotient, remainder = divide(dividend, divisor)

print("Q: ", quotient, ", R: ", remainder)
