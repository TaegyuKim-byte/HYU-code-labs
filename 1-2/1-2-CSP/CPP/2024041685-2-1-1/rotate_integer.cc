#include <iostream>

void rotateLeft(int* pa, int* pb, int* pc) {
	int tem;

	tem = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = tem;
}

void rotateRight(int* pa, int* pb, int* pc) {
	int tem;
	
	tem = *pc;
	*pc = *pb;
	*pb = *pa;
	*pa = tem;
}

int main(void) {
	
	int a = 10;
	int b = 20;
	int c = 30;
	char let = 0;
	int again = 1;

	std::cout << a << " : " << b << " : " << c << std::endl;

	while (again) {

		std::cin >> let;

		if (let == 'L') {
			rotateLeft(&a, &b, &c);
			std::cout << a << " : "  << b  << " : " << c << std::endl;
		} else if (let == 'R') {
			rotateRight(&a, &b, &c);
			std::cout << a << " : " <<  b  << " : " <<  c << std::endl;
		} else if (let == 'E') {
			again = 0;
		} else {
			std::cout << "Error: Wrong Input!" << std::endl;
			again = 0;
		}
				
	}	
	
	return 0;
}	
