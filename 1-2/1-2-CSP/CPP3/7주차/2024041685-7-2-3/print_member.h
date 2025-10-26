#ifndef __PRINT_MEMBER_H__
#define __PRINT_MEMBER_H__
#include <iostream>

class A {
private:
	int* memberA;

public:
	A(int number) {
		memberA = new int(number);
		std::cout << "new memberA" << std::endl;
	}

	virtual ~A() {
		delete memberA;
		std::cout << "delete memberA" << std::endl;
	}

	virtual void print();
};

class B : public A {
private:
	double* memberB;

public:
	B(double number) : A(1) {
		memberB = new double(number);
		std::cout << "new memberB" << std::endl;
	}

	virtual ~B() {
		delete memberB;
		std::cout << "delete memberB" << std::endl;
	}

	virtual void print();
};

class C : public B {
private:
	std::string* memberC;

public:
	C(std::string string) : B(1.1) {
		memberC = new std::string(string);
		std::cout << "new memberC" << std::endl;
	}

	~C() {
		delete memberC;
		std::cout << "delete memberC" << std::endl;
	}

	void print();
};

#endif