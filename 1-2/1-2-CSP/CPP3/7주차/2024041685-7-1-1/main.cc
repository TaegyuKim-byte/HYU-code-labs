#include <iostream>
#include "magic_square.h"

int main(void) {
	
	int size;

	std::cin >> size;

	int **square = new int *[size];

	for (int i = 0; i < size; i++) {
		square[i] = new int[size];

		for (int j = 0; j < size; j++) {
			square[i][j] = 0;
		}
	}

	magic_square(size, square);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << square[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++) {
		delete[] square[i];
	}

	delete[] square;




	return 0;
}
