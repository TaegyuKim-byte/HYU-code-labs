#ifndef __MY_CLOCK_H__
#define __MY_CLOCK_H__
#include <iostream>

class MyClock {
public:
	void Tick(int second = 1);
	//�ʸ� ���� �ð��� ��ȭ�Ҷ� : 24:0:0 ���� ����
	bool SetTime(int hour, int minute, int second); //�ùٸ� ������ �ð����� üũ
	// If input is Invalid, it returns false and does not change the time
	// 23:59:59���� valid��. �ʱ�ȭ�� �� 24:0:0�� Invalid 
	int hour() const;
	int minute() const;
	int second() const;

private:
	int _hour = 0, _min = 0, _sec = 0;
	//You can add any function if needed
};

//The format for input/output is hh:mm:ss 
//��� 0�� ���ڸ��� ���

std::ostream& operator<<(std::ostream& out, const MyClock& c);
std::istream& operator>>(std::istream& in, MyClock& c);

#endif
