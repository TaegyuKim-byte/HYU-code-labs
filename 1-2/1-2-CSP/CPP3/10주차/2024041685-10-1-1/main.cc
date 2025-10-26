#include <iostream>
#include "my_string.h"
#include <string>

int main(void) {
	MyString a, b, strResult;
	std::string commandOrobj1, obj2;
	char op;
	int integer;


	while (true) {
		std::cin >> commandOrobj1;

		if (commandOrobj1 == "new") {
			std::cout << "enter a\n";
			operator>>(std::cin, a);

			std::cout << "enter b\n";
			operator>>(std::cin, b);
		}
		else if (commandOrobj1 == "a") {
			std::cin >> op;
			if (op == '+') {
				std::cin >> obj2;
				if (obj2 == "a") {
					strResult = a.operator+(a);//a+a
					std::cout << strResult << std::endl;
				}
				else {
					strResult = a.operator+(b);//a+b
					std::cout << strResult << std::endl;
				}
			}
			else if (op == '*') {
				std::cin >> integer;
				strResult = a.operator*(integer);//a*integer
				std::cout << strResult << std::endl;
			}
		}
		else if (commandOrobj1 == "b") {
			std::cin >> op;
			if (op == '+') {
				std::cin >> obj2;
				if (obj2 == "a") {
					strResult = b.operator+(a);//b+a
					std::cout << strResult << std::endl;
				}
				else {
					strResult = b.operator+(b);//b+b
					std::cout << strResult << std::endl;
				}
			}
			else if (op == '*') {
				std::cin >> integer;
				strResult = b.operator*(integer);//b*integer
				std::cout << strResult << std::endl;
			}
		}
		else if (commandOrobj1 == "quit") {
			break;
		}
	}
	return 0;
}