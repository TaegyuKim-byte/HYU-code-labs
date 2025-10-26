#include <stdio.h>

int main(void) {
	char cmd;
	int loop = 1;
	int courses[5] = {0, };
	int idx = 0;
	while (loop) {
		printf("r: registration, q: quit\n");
		scanf(" %c", &cmd);
		switch (cmd) {
			case 'r':
				scanf("%d", &courses[idx++]);
				break;
			case 'q':
				loop = 0;
				break;
		}
	}

	for (int i = 0; i < sizeof(courses) 
			/ sizeof(courses[0]); i++) { 
		//if (courses[i] != 0) {
		if (courses[i]) {
			printf("[%d]: %d\n", i + 1, courses[i]);
		}
	}

	return 0;
}
