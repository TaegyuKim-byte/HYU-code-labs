#ifndef __MY_CLOCK_H__
#define __MY_CLOCK_H__
#include <iostream>

class MyClock {
public:
	void Tick(int second = 1);
	//초를 통해 시간을 변화할때 : 24:0:0 까지 가능
	bool SetTime(int hour, int minute, int second); //올바른 범위의 시간인지 체크
	// If input is Invalid, it returns false and does not change the time
	// 23:59:59까지 valid임. 초기화할 때 24:0:0은 Invalid 
	int hour() const;
	int minute() const;
	int second() const;

private:
	int _hour = 0, _min = 0, _sec = 0;
	//You can add any function if needed
};

//The format for input/output is hh:mm:ss 
//대신 0은 한자리로 출력

std::ostream& operator<<(std::ostream& out, const MyClock& c);
std::istream& operator>>(std::istream& in, MyClock& c);

#endif
