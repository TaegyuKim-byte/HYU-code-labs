#ifndef __CALENDAR_H__
#define __CALENDAR_H__
#include <iostream>

class MyCalendar {
public:
	MyCalendar();
	MyCalendar(int year, int month, int day);
	//맨 처음 호출할 때 초기화용
	bool NextDay(int n = 1);
	bool SetDate(int year, int month, int day);
	//이미 호출된 인스턴스에서 값을 변경할 때 사용
	int year() const;
	int month() const;
	int day() const;

private:
	static int GetDaysInYear(int year);
	// 윤년인지 아닌지에 따라 그 해의 총 일수를 반환
	static int ComputeDaysFromYearStart(int year, int month, int day);
	// compute the days from the date given to the current day.
	int _year, _month, _day;
};

//the format is yyyy.m.d

std::ostream& operator<<(std::ostream& out, const MyCalendar& c);
std::istream& operator>>(std::istream& in, MyCalendar& c);

#endif
