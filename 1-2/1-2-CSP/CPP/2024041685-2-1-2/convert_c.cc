#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_case(char* a) {
	for (int i=0; a[i] != '\0'; i++) {
		if ((a[i] >= 65) && (a[i] <= 90)) {
			a[i] = a[i] + 32;
		} 
		else if ((a[i] >= 97) && (a[i] <= 122)) {
			a[i] = a[i] - 32;
		}
		else {
			printf("Error: Wrong input!");
			exit(1);
		}		
	}
}

int main(void) {
	char *str;
	int again=1;
	size_t len = 100;
		
	while (again) {

		str = (char *)malloc(len * sizeof(char));
		
		scanf("%s" , str);
		
		if (strcmp(str, "exit") == 0) {
			free(str);
			exit(0);
		}
	
		convert_case(str);
		
		printf("%s\n", str);
		
		free(str);
	}	
	return 0;
}
