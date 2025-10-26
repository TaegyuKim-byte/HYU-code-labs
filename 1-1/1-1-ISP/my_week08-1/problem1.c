#include <stdio.h>

void printb(unsigned char num);

int main(void) {
	unsigned char a, b, c;
	a = -123;
	b = 32;
	c = a + b;

	printf("  ");
	printb(a);

	printf("+ ");
	printb(b);

	printf("----------\n");
	printf("  ");
	printb(c);
	return 0;
}

void printb(unsigned char num) {
	int i;
	unsigned char div;
	for (i = 0, div = 128; i < 8; i++, div /= 2) {
		if (((num / div) % 2) == 1) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

