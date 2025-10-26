#include "my_string.h"
#include <iostream>
#include <string>

MyString MyString::operator+(const MyString& b) {
	MyString result;
	result.str = this->str + b.str;

	return result;
}

MyString MyString::operator*(const int b) {
	MyString result2;
	result2.str = "";
	 
	for (int i = 0; i < b; i++) {
		result2.str += this->str;
	}

	return result2;
}

std::ostream& operator<<(std::ostream& out, MyString& my_string) { //�̰ɷ� str ���� ��ȯ.(��꿡 �̿�)
	out << my_string.str;
	return out;
}

std::istream& operator>>(std::istream& in, MyString& my_string) { //�̰ɷ� str �ʱ�ȭ
	in >> my_string.str;
	return in;
}