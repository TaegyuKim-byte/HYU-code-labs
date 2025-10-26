#include <stdio.h>

int main(void) {
	unsigned char a, b, c;
	a = -123;
	b = 32;
	c = a + b;
	int i;
	unsigned char div;

	printf("  ");
	for (i = 0, div = 128; i < 8; i++, div /= 2) {
		if (((a / div) % 2) == 1) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");

	printf("+ ");
	for (i = 0, div = 128; i < 8; i++, div /= 2) {
		if (((b / div) % 2) == 1) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");

	printf("----------\n");
	printf("+ ");
	for (i = 0, div = 128; i < 8; i++, div /= 2) {
		if (((c / div) % 2) == 1) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
	return 0;
}
