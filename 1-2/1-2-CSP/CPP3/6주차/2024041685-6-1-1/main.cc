#include <iostream>
#include "shapes.h"
#include <sstream>
#include <string>

int main(void) {

	int size = 10;
	int index = 0;
	std::string input;
	std::string command;
	double value1, value2;

	Shape** shape_arr = new Shape*[size]; //포인터로 배열을 생성하기 위해 동적할당 과정에서 size로 배열크기를 받음.

	while (true) {
		std::getline(std::cin, input);

		std::istringstream iss(input);
		iss >> command >> value1 >> value2;

		if (command == "r") {
			shape_arr[index] = new Rectangle(value1, value2);
			index++;
		}
		else if (command == "t") {
			shape_arr[index] = new Triangle(value1, value2);
			index++;
		}
		else if (command == "0") {
			for (int i = 0; i < index; i++) {
				std::cout << shape_arr[i]->getArea() << std::endl;
				delete shape_arr[i];
			}
			break;
		}
	}

	delete[] shape_arr;

	return 0;
}
