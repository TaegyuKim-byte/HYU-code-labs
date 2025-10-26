#include <stdio.h>

int main(void) {

	int a;
	unsigned int b;

	char c;
	short d;
	long e;

	float f;
	double g;

	printf("int a %ldB\n", sizeof(a));
	printf("unsigned int b %ldB\n", sizeof(b));

	printf("char c %ldB\n", sizeof(c));
	printf("short d %ldB\n", sizeof(d));
	printf("long e %ldB\n", sizeof(e));
	
	printf("float f %ldB\n", sizeof(f));
	printf("double g %ldB\n", sizeof(g));

	return 0;
}
