#include <stdio.h>

int num;
int ret;

void is_prime_number() {
	printf("%d\n", num);
	for (int i = 2; i < num; i++) {
		if ((num % i) == 0)
			ret = 0;
			return;
			//return 0;
	}
	ret = 1;
	//return 2;
}

int main(void) {
	scanf("%d", &num);
	// is_prime_number will return ??? 
	is_prime_number();
	if (ret) {
		printf("%d is a prime number\n", num);
	} else {
		printf("%d is not a prime number\n", num);
	}
	return 0;
}
