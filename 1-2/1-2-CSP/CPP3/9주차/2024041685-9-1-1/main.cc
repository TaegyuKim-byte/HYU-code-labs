#include <iostream>
#include "message.h"
#include <vector>
#include <map>
#include <string>

int main(void) {

	MessageBook MessageList;
	std::string input, command;
	int phoneNum;
	std::string message;
	std::vector<int> phoneList;

	while (true) {
		std::cin >> command;

		if (command == "add") {
			std::cin >> phoneNum;
			std::cin.ignore();
			std::getline(std::cin, input);

			MessageList.AddMessage(phoneNum, input);
		}
		else if (command == "delete") {
			std::cin >> phoneNum;

			MessageList.DeleteMessage(phoneNum);
		}
		else if (command == "print") {
			std::cin >> phoneNum;

			std::cout << MessageList.GetMessage(phoneNum) << std::endl;
		}
		else if (command == "list") {
			phoneList = MessageList.GetNumbers();

			for (int number_ : phoneList) {
				std::cout << number_ << ": " << MessageList.GetMessage(number_) << std::endl;
			}
		}
		else if (command == "quit") {
			return 0;
		}
	}

	return 0;
}
