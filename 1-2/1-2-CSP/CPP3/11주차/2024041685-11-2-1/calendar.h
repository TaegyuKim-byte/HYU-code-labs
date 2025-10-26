#ifndef __CALENDAR_H__
#define __CALENDAR_H__
#include <iostream>

class MyCalendar {
public:
	MyCalendar();
	MyCalendar(int year, int month, int day);
	//�� ó�� ȣ���� �� �ʱ�ȭ��
	bool NextDay(int n = 1);
	bool SetDate(int year, int month, int day);
	//�̹� ȣ��� �ν��Ͻ����� ���� ������ �� ���
	int year() const;
	int month() const;
	int day() const;

private:
	static int GetDaysInYear(int year);
	// �������� �ƴ����� ���� �� ���� �� �ϼ��� ��ȯ
	static int ComputeDaysFromYearStart(int year, int month, int day);
	// compute the days from the date given to the current day.
	int _year, _month, _day;
};

//the format is yyyy.m.d

std::ostream& operator<<(std::ostream& out, const MyCalendar& c);
std::istream& operator>>(std::istream& in, MyCalendar& c);

#endif
