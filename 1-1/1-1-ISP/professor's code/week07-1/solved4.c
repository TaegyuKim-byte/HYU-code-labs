#include <stdio.h>

int main(void) {

	char c;
	printf("Enter a letter: ");
	scanf("%c", &c);

	//if ('a' <= c && c <= 'z') {
	if (97 <= c && c <= 122) {
		c = c - 32;
	}

	printf("%c %d\n", c, c);


	return 0;
}
