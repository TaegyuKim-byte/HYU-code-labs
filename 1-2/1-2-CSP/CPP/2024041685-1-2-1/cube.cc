#include <iostream>

int result=0;

int cube(const int* pd) {
	result = (*pd) * (*pd) * (*pd);
	return result;
}

int main(void) {
	int num1;
	std::cin >> num1;
	int result2 = cube(&num1);

	std::cout << result2 << std::endl;
	
	return 0;
}


