#include <stdio.h>

int main(void) {
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);

//	if ((num % 2) == 1) {
	if (num % 2) {
		printf("Your number %d is odd.\n", num);
	} else {
		printf("Your number %d is even.\n", num);
	}
	return 0;
}
