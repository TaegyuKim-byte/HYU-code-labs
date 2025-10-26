#include <stdio.h>

void prime_factors(int num) {
	for (int i = 1; i <= num; i++) {
		if ((num % i) == 0) {
			printf("%d\n", i);
		}
	}
}

int main(void) {
	int num;
	// scanf();
	num = 14;
	// prime_factors() prints all prime factors of the given number
	prime_factors(num);
	return 0;
}
