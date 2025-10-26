#include "my_vector.h"
#include <iostream>
#include <string>
#include <vector>


int main(void) {
	std::string CommandOrObj1, Obj2;
	char op;
	int arrlen, integer;
	Myvector* a = nullptr, * b = nullptr, arrintResult; //�����ͷ� ����

	while (true) {
		std::cin >> CommandOrObj1;
		
		if (CommandOrObj1 == "new") {

			//std::cin >> arrlen;
			//Myvector a(arrlen), b(arrlen), arrintResult(arrlen);
			//�̷��� ����� ������ ������ ���� �����ϴ� �����δ� �迭 ũ�⸦ ������ �� ����
			//��Ÿ�ӿ� �ѹ� �����Ǹ� ���̻� ������ �Ұ��ϱ� ����
			//���ο� �迭�� �����ϰ� ���� ��������� ��
			//�ٵ� �ݺ��ؼ� ���� �Է¹޾ƾ� �ϴϱ� .. vector �� ����ҵ�

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