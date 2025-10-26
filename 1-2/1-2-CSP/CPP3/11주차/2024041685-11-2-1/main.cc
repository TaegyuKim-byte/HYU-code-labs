#include "calendar.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main(void) {
	MyCalendar calendar;
	std::string input, command, dayOrint, trash1, trash2;
	int y, m, d, offset;

	while (true) {
		std::cin >> command;

		if (command == "set") {
			
			std::cin >> input;

			std::replace(input.begin(), input.end(), '.', ' ');

			std::stringstream ss(input);

			ss >> y >> m >> d;

			if (calendar.SetDate(y, m, d)) {
				std::cout << calendar.year() << "." << calendar.month() << "." << calendar.day() << std::endl;
			}
			else {
				std::cout << "Invalid date: " << y << "." << m << "." << d << std::endl;
				std::cout << calendar.year() << "." << calendar.month() << "." << calendar.day() << std::endl;
			}
		}
		else if (command == "next") {
			std::cin >> dayOrint;

			if (dayOrint == "day") {
				if (calendar.NextDay(1)) {
					std::cout << calendar.year() << "." << calendar.month() << "." << calendar.day() << std::endl;
				}
				else {
					std::cout << "Invalid date\n";
					std::cout << calendar.year() << "." << calendar.month() << "." << calendar.day() << std::endl;
				}
			}
			else {
				offset = std::stoi(dayOrint);

				if (calendar.NextDay(offset)) {
					std::cout << calendar.year() << "." << calendar.month() << "." << calendar.day() << std::endl;
				}
				else {
					std::cout << "Invalid date\n";
					std::cout << calendar.year() << "." << calendar.month() << "." << calendar.day() << std::endl;
				}
			}
		}
		else if (command == "quit") {
			break;
		}
	}

	return 0;
}