#include <iostream>
#include <vector>
#include "intset.h"

int main(void) {
	intset IntSet;
	std::string command;
	int number;

	while (true) {
		std::cin >> command >> number;

		if (command == "add") {
			IntSet.AddNumber(number);
			
			std::vector<int> allNumbers = IntSet.GetAll();
			for (int num : allNumbers) {
				std::cout << num << " ";
			}
			std::cout << std::endl;
		}
		else if (command == "del") {
			IntSet.DeleteNumber(number);
			
			std::vector<int> allNumbers = IntSet.GetAll();
			for (int num : allNumbers) {
				std::cout << num << " ";
			}
			std::cout << std::endl;
		}
		else if (command == "get") {
			std::cout << IntSet.GetItem(number) << std::endl;
		}
		else if (command == "quit") {
			break;
		}
	}

	return 0;
}