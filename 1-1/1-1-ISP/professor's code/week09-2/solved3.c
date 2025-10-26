#include <stdio.h>

int main(void) {

	int arr[8] = {1, 4, 8, 3, 7, 2, 6, 5};
	int* parr = &arr[0];

	for (; parr < &arr[8]; parr++) {
		printf("%d ", *parr);
	}
	printf("\n");

	return 0;
}
