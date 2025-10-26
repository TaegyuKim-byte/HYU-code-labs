#include "calendar.h"

MyCalendar::MyCalendar() {

}

MyCalendar::MyCalendar(int year, int month, int day) : _year(year), _month(month), _day(day) {

}

bool MyCalendar::NextDay(int n) {
	int ownyear, ownmonth, ownday;
	ownyear = _year;
	ownmonth = _month;
	ownday = _day;

	if (n == 0) return true;

	while (n != 0) {
		if (n > 0) {
			int daysInMonth = ComputeDaysFromYearStart(_year, _month + 1, 0) - ComputeDaysFromYearStart(_year, _month, 0);
			
			if ((_day + n) <= daysInMonth) {
				_day += n;
				n = 0;
			}
			else {
				n -= (daysInMonth - _day + 1);
				_day = 1;
				_month += 1;

				if (_month > 12) {
					_month = 1;
					_year += 1;
				}
			}
		}
		else {
			if (_day + n >= 1) {
				_day = _day + n;
				n = 0;
			}
			else {
				_day = ComputeDaysFromYearStart(_year, _month, 0) - ComputeDaysFromYearStart(_year, _month - 1, 0);
				if (--_month < 1) {
					_month = 12;
					--_year;
				}
			}
		}

		if (!SetDate(_year, _month, _day)) {
			_year = ownyear;
			_month = ownmonth;
			_day = ownday;

			return false;
		}
	}

	return true;
}

bool MyCalendar::SetDate(int year, int month, int day) {
	if (year >= 0 && year <= 9999 && month >= 1 && month <= 12) {
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (day >= 1 && day <= 29) {
					_year = year;
					_month = month;
					_day = day;

					return true;
				}
			}
			else {
				if (day >= 1 && day <= 28) {
					_year = year;
					_month = month;
					_day = day;

					return true;
				}
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 
		|| month == 10 || month == 12) {
			if (day >= 1 && day <= 31) {
				_year = year;
				_month = month;
				_day = day;

				return true;
			}
		}
		else {
			if (day >= 1 && day <= 30) {
				_year = year;
				_month = month;
				_day = day;

				return true;
			}
		}
	}

	return false;
}

int MyCalendar::year() const {
	return _year;
}

int MyCalendar::month() const {
	return _month;
}

int MyCalendar::day() const {
	return _day;
}

int MyCalendar::GetDaysInYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 366;
	}
	else {
		return 365;
	}
}

int MyCalendar::ComputeDaysFromYearStart(int year, int month, int day) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (isLeapYear) {
		daysInMonth[1] = 29;
	}

	int totalDays = 0;

	for (int i = 0; i < month - 1; i++) {
		totalDays += daysInMonth[i];
	}

	totalDays += day;

	return totalDays;
}

std::ostream& operator<<(std::ostream& out, const MyCalendar& c) {
	out << c.year() << "." << c.month() << "." << c.day() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, MyCalendar& c) {
	char trash1, trash2;
	int year, month, day;

	in >> year >> trash1 >> month >> trash2 >> day;

	if (!c.SetDate(year, month, day)) {
		in.setstate(std::ios::failbit);
	}

	return in;
}