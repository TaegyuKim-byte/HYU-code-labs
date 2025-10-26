#include <stdio.h>

int fib(int n);

int fib_results[10] = {0, };

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d\n", fib(num));
	return 0;
}

int fib(int n) {
	printf("fib(%d)\n", n);
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else {
		if (fib_results[n] == 0) {
			fib_results[n] = fib(n-1) + fib(n-2);
		}
		return fib_results[n];
	}
}
