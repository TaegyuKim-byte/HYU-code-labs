#include <iostream>
#include "print_info.h"

void printObjectType1(A* object) {
	object->getTypeInfo();
}

void printObjectType2(A& object) {
	object.getTypeInfo();
}

int main() {

	A* objects[3];

	objects[0] = new A();
	objects[1] = new B();
	objects[2] = new C();

	//������ �迭�� �����ϴ� ��.. 
	//�� �ʿ� ����? �׳� �ּ� �Ѱ��ָ� �ǳ�????

	for (int i = 0; i < 3; i++) {
		printObjectType1(objects[i]);
		printObjectType2(*objects[i]);
	}

	return 0;
}
