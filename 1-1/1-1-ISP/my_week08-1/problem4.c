#include <stdio.h>

int num;

void prime_factors() {
	for (int i = 1; i <= num; i++) {
		if ((num % i) == 0) {
			printf("%d\n", i);
		}
	}
}

int main(void) {
	// scanf();
	num = 14;
	// prime_factors() prints all prime factors of the given number
	prime_factors();
	num = 15;
	// prime_factors() prints all prime factors of the given number
	prime_factors();
	return 0;
}
