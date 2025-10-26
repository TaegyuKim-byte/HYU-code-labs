#include "my_vector.h"
#include <iostream>
#include <string>

Myvector::Myvector() : a(nullptr), length(0) {

}

Myvector::Myvector(int length) : length(length) {
	//�迭�� ������ �ʿ���.

	a = new int[length]; //a�� �̹� ����Ǿ������Ƿ� new�� ���ָ� ��
}

Myvector::~Myvector() {
	delete[] a;
}

Myvector& Myvector::operator=(const Myvector& b) {
	if (this == &b) 
		return *this;

	delete[] this->a; 

	length = b.length; 
	this->a = new int[length]; 
	for (int i = 0; i < length; i++) {
		this->a[i] = b.a[i]; 
	}

	return *this;
}


Myvector Myvector::operator+(const Myvector& b) {
	Myvector result(length);

	for (int i = 0; i < length; i++) {
		result.a[i] = this->a[i] + b.a[i];
	}

	return result;
}

Myvector Myvector::operator-(const Myvector& b) {
	Myvector result(length);

	for (int i = 0; i < length; i++) {
		result.a[i] = this->a[i] - b.a[i];
	}

	return result;
}

Myvector Myvector::operator+(const int b) {
	Myvector result(length);

	for (int i = 0; i < length; i++) {
		result.a[i] = this->a[i] + b;
	}

	return result;
}

Myvector Myvector::operator-(const int b) {
	Myvector result(length);

	for (int i = 0; i < length; i++) {
		result.a[i] = this->a[i] - b;
	}

	return result;
}

std::ostream& operator<< (std::ostream& out, const Myvector& b) {
	for (int i = 0; i < b.length; i++) {
		out << b.a[i] << " ";
	}	
	return out;
}

std::istream& operator>> (std::istream& in, Myvector& b) {
	for (int i = 0; i < b.length; i++) {
		in >> b.a[i];
	}
	return in;
}