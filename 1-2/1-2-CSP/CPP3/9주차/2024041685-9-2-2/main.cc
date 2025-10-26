#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include "sorted.h"

int main(void) {
	SortedArray sorArr;
	std::string command;

	while (true) {
		std::cin >> command;
		std::cin.ignore();

		if (command == "add") {
			std::string input;
			std::vector<int> numList;
			std::vector<int>::iterator it;
			int num;

			std::getline(std::cin, input);

			std::istringstream iss(input);
			while (iss >> num) {
				numList.push_back(num);
			}

			for (it = numList.begin(); it != numList.end(); it++) {
				sorArr.AddNumber(*it);
			}
		}
		else if (command == "ascend") {
			std::vector<int> num;
			std::vector<int>::iterator it;

			num = sorArr.GetSortedAscending();
			for (it = num.begin(); it != num.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << "\n";
		}
		else if (command == "descend") {
			std::vector<int> num;
			std::vector<int>::iterator it;

			num = sorArr.GetSortedDescending();
			for (it = num.begin(); it != num.end(); it++) {
				std::cout << *it << " ";
			}
			
			std::cout << "\n";
		}
		else if (command == "max") {
			int max;

			max = sorArr.GetMax();

			std::cout << max << std::endl;
		}
		else if (command == "min") {
			int min; 

			min = sorArr.GetMin();

			std::cout << min << std::endl;
		}
		else if (command == "quit") {
			break;
		}
	}
	return 0;
}