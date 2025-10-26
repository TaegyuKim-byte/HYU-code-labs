#include <stdio.h>

int main(void) {
	int num, i, count;
	printf("Enter a number : ");
	scanf("%d", &num);

	switch (num) {
		case 2: case 3: case 5: case 7:
			printf("Your number is a prime number.\n");
			break;
		default:
			printf("Your number is NOT a prime number.\n");
	}
	/*
	for (i = 2, count = 0; i < num; i++) {
		if ((num % i) == 0) {
			count++;
		}
	}

	if (count == 0) {
		printf("Your number is a prime number.\n");
	} else {
		printf("Your number is NOT a prime number.\n");
	}
	*/

	return 0;
}
