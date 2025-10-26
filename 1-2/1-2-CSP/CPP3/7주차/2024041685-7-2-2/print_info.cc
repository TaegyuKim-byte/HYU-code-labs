#include "print_info.h"
#include <iostream>

void A::getTypeInfo() {
	std::cout << "This is an instance of class A" << std::endl;
}

void B::getTypeInfo() {
	std::cout << "This is an instance of class B" << std::endl;
}

void C::getTypeInfo() {
	std::cout << "This is an instance of class C" << std::endl;
}
