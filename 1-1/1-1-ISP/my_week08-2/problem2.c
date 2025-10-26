#include <stdio.h>

int fact(int n) {
	if (n == 1)
		return 1;
	else 
		return n * fact(n - 1);
}

int main(void) {
	int i, val;
	for (i = 2, val = 1; i < 6; i++) {
		val *= i;
	}
	printf("%d\n", val);
	printf("%d\n", fact(5));
	return 0;
}
