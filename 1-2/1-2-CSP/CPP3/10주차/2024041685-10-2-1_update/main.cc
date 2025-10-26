#include "my_vector.h"
#include <iostream>
#include <string>
#include <vector>


int main(void) {
	std::string CommandOrObj1, Obj2;
	char op;
	int arrlen, integer;
	Myvector* a = nullptr, * b = nullptr, arrintResult; //포인터로 선언

	while (true) {
		std::cin >> CommandOrObj1;
		
		if (CommandOrObj1 == "new") {

			//std::cin >> arrlen;
			//Myvector a(arrlen), b(arrlen), arrintResult(arrlen);
			//이렇게 사이즈를 저장할 변수의 값을 변경하는 것으로는 배열 크기를 변경할 수 없음
			//런타임에 한번 결정되면 더이상 변경이 불가하기 때문
			//새로운 배열을 선언하고 값을 변경해줘야 함
			//근데 반복해서 값을 입력받아야 하니까 .. vector 를 써야할듯

			std::cin >> arrlen;

			delete a;
			a = new Myvector(arrlen);

			delete b;
			b = new Myvector(arrlen);

			std::cout << "enter a\n";
			operator>>(std::cin, *a);

			std::cout << "enter b\n";
			operator>>(std::cin, *b);

		}
		else if (CommandOrObj1 == "a") {
			std::cin >> op;
			if (op == '+') {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = *a + *a;//a+a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = *a + *b;//a+b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi(Obj2);
					arrintResult = *a + integer;//a+int
					std::cout << arrintResult << std::endl;
				}
			}
			else {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = *a - *a;//a-a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = *a - *b;//a-b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi (Obj2);
					arrintResult = *a - integer;//a-int
					std::cout << arrintResult << std::endl;
				}
			}
		}
		else if (CommandOrObj1 == "b") {
			std::cin >> op;
			if (op == '+') {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = *b + *a;//b+a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = *b + *b;//b+b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi(Obj2);
					arrintResult = *b + integer;//b+int
					std::cout << arrintResult << std::endl;
				}
			}
			else {
				std::cin >> Obj2;
				if (Obj2 == "a") {
					arrintResult = *b - *a;//b-a
					std::cout << arrintResult << std::endl;
				}
				else if (Obj2 == "b") {
					arrintResult = *b - *b;//b-b
					std::cout << arrintResult << std::endl;
				}
				else {
					integer = std::stoi(Obj2);
					arrintResult = *b - integer;//b-int
					std::cout << arrintResult << std::endl;
				}
			}
		}
		else if (CommandOrObj1 == "quit") {
			delete a;
			delete b;
			break;
		}
	}
	
	return 0;
}