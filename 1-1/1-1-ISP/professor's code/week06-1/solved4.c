#include <stdio.h>

int main(void) {
	int i, j;
	i = j = 0;
	printf("%d\n", i++);
	j = i++;
	printf("%d\n", j);
	return 0;
}
