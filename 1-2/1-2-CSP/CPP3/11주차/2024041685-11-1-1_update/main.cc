#include <iostream>
#include "my_clock.h"
#include <string>
#include <sstream>

int main() {
	MyClock clock;
	std::string command, trash;
	std::string input, original_input;
	int dt;

	while (true) {
		int dt, h, m, s;
		std::cin >> command;

		if (command == "set") {
			std::getline(std::cin, input);
			original_input = input;

			std::istringstream input_stream(input);

			if (input_stream >> clock) {
				std::cout << clock.hour() << ":" << clock.minute() << ":" << clock.second() << std::endl;
			}
			else {
				std::cout << "Invalid time:" << original_input << "\n";
				std::cout << clock.hour() << ":" << clock.minute() << ":" << clock.second() << std::endl;
			}

		}
		else if (command == "tick") {
			std::cin >> dt;
			clock.Tick(dt);

			std::cout << clock.hour() << ":" << clock.minute() << ":" << clock.second() << std::endl;
		}
		else if (command == "quit") {
			break;
		}
		else {
			std::cout << "wrong input" << std::endl;
		}
	}

	return 0;
}