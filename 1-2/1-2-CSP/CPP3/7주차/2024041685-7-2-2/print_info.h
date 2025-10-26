#ifndef __PRINT_INFO_H__
#define __PRINT_INFO_H__
#include <iostream>

class A {
public:
	virtual void getTypeInfo();
};

class B : public A {
public:
	virtual void getTypeInfo();

};

class C : public B {
public:
	void getTypeInfo();

};

#endif