#include <iostream>
#include "animal.h"
#include <sstream>
#include <string>

int main() {

	int size = 10;
	int index = 0;
	std::string input;
	std::string command;
	int numforZeb, ageof;
	std::string nameof, strforCat;

	Animal** animal_arr = new Animal * [size];

	while (true) {
		std::getline(std::cin, input);

		std::istringstream iss(input);

		iss >> command;

		if (command == "z") {
			iss >> nameof >> ageof >> numforZeb;
			animal_arr[index] = new Zebra(nameof, ageof, numforZeb);
			index++;
		}
		else if (command == "c") {
			iss >> nameof >> ageof >> strforCat;
			animal_arr[index] = new Cat(nameof, ageof, strforCat);
			index++;
		}
		else if (command == "0") {
			for (int i = 0; i < index; i++) {
				animal_arr[i]->printInfo();
				delete animal_arr[i];
			}
			break;
		}
	}

	delete[] animal_arr;

	return 0;
}
