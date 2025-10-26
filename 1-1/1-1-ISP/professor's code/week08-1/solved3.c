#include <stdio.h>

int is_prime_number(int num) {
	for (int i = 2; i < num; i++) {
		if ((num % i) == 0)
			return 0;
	}
	return 2;
}

int main(void) {
	int num;
	scanf("%d", &num);
	// is_prime_number will return ??? 
	if (is_prime_number(num)) {
		printf("%d is a prime number\n", num);
	} else {
		printf("%d is not a prime number\n", num);
	}
	return 0;
}
