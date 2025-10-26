#ifndef __CLASSES_H__
#define __CLASSES_H__

#include <iostream>

class A {
	public:
		virtual void test();
};

class B : public A {
	public:
		virtual void test();
};

class C : public B {
	public:
		void test();
};
#endif
