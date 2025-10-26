#include <stdio.h>

int main(void) {

	int i;
	long a = 5215571311076468480UL;
	long div = 0x0100000000000000UL;
	char c;
	printf("%lx\n", a / 0x0100000000000000UL);
	printf("%lx\n", a / 0x0001000000000000UL);
	printf("%lx\n", a / 0x0000010000000000UL);
	printf("%lx\n", a / 0x0000000100000000UL);
	printf("%lx\n", a / 0x0000000001000000UL);
	printf("%lx\n", a / 0x0000000000010000UL);
	printf("%lx\n", a / 0x0000000000000100UL);
	printf("%lx\n", a / 0x0000000000000001UL);

	for (i = 0; i < 8; i++) {
		c = a / div;
		printf("%c", c);
		div /= 0x100;
	}
	printf("\n");

	/*
	c = a / 0x0100000000000000UL;
	printf("%c %x\n", c, c);
	c = a / 0x0001000000000000UL;
	printf("%c %x\n", c, c);
	c = a / 0x0000010000000000UL;
	printf("%c %x\n", c, c);
	c = a / 0x0000000100000000UL;
	printf("%c %x\n", c, c);
	c = a / 0x0000000001000000UL;
	printf("%c %x\n", c, c);
	c = a / 0x0000000000010000UL;
	printf("%c %x\n", c, c);
	c = a / 0x0000000000000100UL;
	printf("%c %x\n", c, c);
	c = a / 0x0000000000000001UL;
	printf("%c %x\n", c, c);
	*/
	return 0;
}
