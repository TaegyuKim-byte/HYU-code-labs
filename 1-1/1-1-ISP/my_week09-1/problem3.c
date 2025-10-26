#include <stdio.h>

int main(void) {
	int val = 0;
	char str[4];
	int val1 = 0;

	printf("str: %p val: %p val1: %p\n", 
			str, &val, &val1);
	scanf("%s", str);
	printf("str: %s val: %d\n", str, val);

	return 0;
}
