#include <stdio.h>

int main(void) {
	double c;
	int f;
	printf("Enter the temperature in degrees Celsius: ");
	scanf("%lf", &c);
	f = c * 9 / 5 + 32;
	printf("The temperature is %d degrees Fahrenheit.\n", f);
	return 0;
}
