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
	//reverse();
	int i;
	char str[11];
	scanf("%s", str);
	for (i = 0; i < sizeof(str) 
			/ sizeof(str[0]); i++) {
		if (str[i] == '\0') {
			break;
		}
	}
	for (; i >= 0; i--) {
		printf("%c", str[i - 1]);
	}
	printf("\n");
	return 0;
}
