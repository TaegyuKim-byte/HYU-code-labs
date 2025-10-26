#include "my_clock.h"

void MyClock::Tick(int seconds) {
    if (seconds >= 0) {
        // �ð��� ����� ��
        _sec += seconds;
        _min += _sec / 60;
        _hour += _min / 60;

        // ��, ��, �ð��� 24�ð� ���� ����
        _sec %= 60;
        _min %= 60;
        _hour %= 24;

        // 24�ø� ���� �ʵ��� �ϸ鼭 00:00:00���� �Ѿ�� �κ� ó��
        if (_hour == 0 && _min == 0 && _sec == 0) {
            _hour = 24;
            _min = 0;
            _sec = 0;  // 24:00:00 ���Ŀ��� 00:00:01�� ����
        }
    }
    else {
        // �ð��� ������ ��
        int total_seconds = _hour * 3600 + _min * 60 + _sec + seconds;

        // �ð��� ������ �Ѿ �� 24�ð��� ���Ͽ� ����� �������
        if (total_seconds < 0) {
            total_seconds += 24 * 3600;
        }

        // �ð��� �ٽ� ��, ��, �ʷ� ������ ����
        _hour = (total_seconds / 3600) % 24;
        total_seconds %= 3600;
        _min = (total_seconds / 60) % 60;
        _sec = total_seconds % 60;
    }
}

bool MyClock::SetTime(int hour, int minute, int second) {
	if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60) {
		_hour = hour;
		_min = minute;
		_sec = second;

		return true;
	}
	return false;
}

int MyClock::hour() const {
	return _hour;
}

int MyClock::minute() const {
	return _min;
}

int MyClock::second() const {
	return _sec;
}

//MyClock ������ �Լ� �ƴ�. 

std::ostream& operator<<(std::ostream& out, const MyClock& c) {
	out << c.hour() << ":" << c.minute() << ":" << c.second() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, MyClock& c) {
	int h, m, s;
	char delim1, delim2;

	in >> h >> delim1 >> m >> delim2 >> s;

	if (in.fail() || delim1 != ':' || delim2 != ':' || !c.SetTime(h, m, s)) {
		in.setstate(std::ios::failbit); // ���� ���� ����
	}
	return in; 
}
