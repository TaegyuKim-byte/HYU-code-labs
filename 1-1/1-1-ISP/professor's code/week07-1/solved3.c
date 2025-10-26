#include <stdio.h>

int main(void) {
	long pricipal, period;
	int i, interest;
	long total;

	printf("Principal, Period: ");
	scanf("%ld %ld", &pricipal, &period);
	interest = 10;

	interest = pricipal / 100 * interest;
	for (i = 0, total = pricipal; i < period; i++) {
		total += interest;
	}

	printf("Total: %ld\n", total);
	return 0;
}
