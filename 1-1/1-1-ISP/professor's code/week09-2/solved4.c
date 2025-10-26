#include <stdio.h>

int main(void) {

	char str[32] = {0, };
	char* p = str;
	int i;

	while (*p != '.') {
		scanf("%s", p);
		for (; p < &str[32]; p++) {
			if (*p == 0) {
				*p = 32;
				printf("len: %ld\n", p - &str[0]);
				p++;
				break;
			}
		}
	}
	
	printf("%s\n", str);


	return 0;
}
