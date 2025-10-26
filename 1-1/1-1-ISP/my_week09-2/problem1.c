#include <stdio.h>

int main(void) {
	char* a; short* b; int* c; long* d;

	printf("Bytes required for\n a: %ldB, b: %ldB, c: %ldB, d: %ldB\n\n",
			sizeof(a), sizeof(b), sizeof(c), sizeof(d));

	printf("Bytes pointed by\n a: %ldB, b: %ldB, c: %ldB, d: %ldB\n",
			sizeof(*a), sizeof(*b), sizeof(*c), sizeof(*d));

	return 0;
}
