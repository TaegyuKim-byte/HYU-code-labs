#include <stdio.h>

int main(void) {
	unsigned long data = 0x48616E79616E67UL;
	unsigned long div = 0x1UL;
	int i, pos = 4;
	char letter;

	scanf("%d", &pos);
	for (i = 7; i > pos; i--) {
		div *= 0x0100UL;
	}

	letter = data / div;

	if (97 <= letter && letter <= 122) {
		letter -= 32;
	}

	printf("%c", letter);

	return 0;
}
