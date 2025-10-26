#include <stdio.h>

int main(void) {
	int a = 0;
	int* pa = &a;
	float* pb = (float*) &a;

	// How to print each value pointed by pa and pb
	printf("*pa: %d *pb: %f\n", *pa, *pb);

	// What happens after updating a to 1
	*pa = 1;
	printf("*pa: %d *pb: %f\n", *pa, *pb);

	*pb = 1;
	// What happens after updating *pb to 1f
	printf("*pa: %d *pb: %f\n", *pa, *pb);

	return 0;
}


