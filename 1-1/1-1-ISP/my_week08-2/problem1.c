#include <stdio.h>

void r_counter(int n) {
	if (n == 0) 
		return;
	else
		r_counter(n - 1);
		printf("%d\n", n);
}

int main(void) {

	r_counter(10);

	return 0;
}
