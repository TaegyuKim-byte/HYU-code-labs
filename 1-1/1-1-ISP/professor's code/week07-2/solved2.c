#include <stdio.h>

int main(void) {
	double val;
	int i;
	scanf("%lf", &val);
	printf("%lf\n", val);
	i = val;
	printf("%d %lf\n", i, val - i);

	return 0;
}
