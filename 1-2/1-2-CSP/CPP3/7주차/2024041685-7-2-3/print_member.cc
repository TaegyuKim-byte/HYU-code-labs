#include <iostream>
#include "print_member.h"

void A::print() {
	std::cout << "*memberA " << *memberA << std::endl;
}

void B::print() {
	A::print();
	std::cout << "*memberB " << *memberB << std::endl;
}

void C::print() {
	B::print();
	std::cout << "*memberC " << *memberC << std::endl;
}
