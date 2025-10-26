#include "classes.h"
#include <iostream>

int main() {

	A* ptra = new A();
	A* ptrb = new B();
	A* ptrc = new C();

	ptra->test();
	ptrb->test();
	ptrc->test();

	delete ptra;
	delete ptrb;
	delete ptrc;

	return 0;
}
