#include <stdio.h>

int main(void) {
	int num1, num2;
	printf("Enter two number: ");
	scanf("%d %d", &num1, &num2);
	printf("Your numbers: %d %d\n", num1, num2);
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = Q: %d R: %d\n", num1, num2, 
			num1 / num2, num1 % num2);
	return 0;
}
