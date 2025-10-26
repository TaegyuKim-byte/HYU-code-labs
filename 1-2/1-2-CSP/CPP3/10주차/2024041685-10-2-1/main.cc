#include "my_vector.h"
#include <iostream>
#include <string>

int main(void) {
	std::string CommandOrObj1, Obj2;
	char op;
	int integer, arrlen;

	std::cin >> CommandOrObj1 >> arrlen;

	Myvector a(arrlen), b(arrlen), arrintResult(arrlen);

	std::cout << "enter a\n";
	operator>>(std::cin, a);

	std::cout << "enter b\n";
	operator>>(std::cin, b);
	

	while (true) {
		std::cin >> CommandOrObj1;
		
		if (CommandOrObj1 == "new") {
			std::cin >> arrlen;

			std::cout << "enter a\n";
			operator>>(std::cin, a);

			std::cout << "enter b\n";
			operator>>(std::cin, b);
		}
		else if (CommandOrObj1 == "a") {
			std::cin >> op;
			if (op == '+') {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = a.operator+(a);//a+a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = a.operator+(b);//a+b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi(Obj2);
					arrintResult = a.operator+(integer);//a+int
					std::cout << arrintResult << std::endl;
				}
			}
			else {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = a.operator-(a);//a-a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = a.operator-(b);//a-b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi (Obj2);
					arrintResult = a.operator-(integer);//a-int
					std::cout << arrintResult << std::endl;
				}
			}
		}
		else if (CommandOrObj1 == "b") {
			std::cin >> op;
			if (op == '+') {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = b.operator+(a);//b+a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = b.operator+(b);//b+b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi(Obj2);
					arrintResult = b.operator+(integer);//b+int
					std::cout << arrintResult << std::endl;
				}
			}
			else {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = b.operator-(a);//b-a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = b.operator-(b);//b-b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi(Obj2);
					arrintResult = b.operator-(integer);//b-int
					std::cout << arrintResult << std::endl;
				}
			}
		}
		else if (CommandOrObj1 == "quit") {
			break;
		}
	}
	
	return 0;
}