#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__
#include <iostream>

class Myvector {
public:
	Myvector();
	Myvector(int length);
	~Myvector();

	Myvector& operator=(const Myvector & b); 
	Myvector operator+(const Myvector & b);
	Myvector operator-(const Myvector & b);
	Myvector operator+(const int b);
	Myvector operator-(const int b);
	friend std::ostream& operator<< (std::ostream& out, const Myvector& b);
	friend std::istream& operator>> (std::istream& in, Myvector& b);

private:
	int length; //�迭�� ũ��
	int* a; //�迭
};

#endif
