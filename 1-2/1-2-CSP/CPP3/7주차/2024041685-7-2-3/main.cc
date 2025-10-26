#include <iostream>
#include "print_member.h"

int main(void) {

	int numA;
	double numB;
	std::string strC;

	std::cin >> numA >> numB >> strC;

	A* arr[3];

	arr[0] = new A(numA);
	arr[1] = new B(numB);
	arr[2] = new C(strC);

	for (int i = 0; i < 3; i++) {
		arr[i]->print();
	}

	for (int i = 0; i < 3; i++) {
		delete arr[i];
	}



	return 0;
}
