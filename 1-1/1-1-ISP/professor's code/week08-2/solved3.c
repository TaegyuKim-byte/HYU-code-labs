#include <stdio.h>

void reverse() {
	char c;
	scanf("%c", &c);
	if (c == '\n')
		return;
	else 
		reverse();
		printf("%c", c);
}

int main(void) {
	reverse();
	printf("\n");
	return 0;
}
