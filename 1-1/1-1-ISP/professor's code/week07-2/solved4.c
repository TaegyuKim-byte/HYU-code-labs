#include <stdio.h>

int main(void) {
	int i;

	for (i = 32; i < 127; i++) {
		printf("%4d\t0x%X\t%c\n", i, i, i);

	}

	return 0;
}
