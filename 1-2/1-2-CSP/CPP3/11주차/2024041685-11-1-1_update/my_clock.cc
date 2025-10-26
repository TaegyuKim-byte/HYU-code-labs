#include "my_clock.h"

void MyClock::Tick(int seconds) {
    if (seconds >= 0) {
        // 시간이 양수일 때
        _sec += seconds;
        _min += _sec / 60;
        _hour += _min / 60;

        // 초, 분, 시간을 24시간 내로 제한
        _sec %= 60;
        _min %= 60;
        _hour %= 24;

        // 24시를 넘지 않도록 하면서 00:00:00으로 넘어가는 부분 처리
        if (_hour == 0 && _min == 0 && _sec == 0) {
            _hour = 24;
            _min = 0;
            _sec = 0;  // 24:00:00 이후에는 00:00:01로 시작
        }
    }
    else {
        // 시간이 음수일 때
        int total_seconds = _hour * 3600 + _min * 60 + _sec + seconds;

        // 시간이 음수로 넘어갈 때 24시간을 더하여 양수로 만들어줌
        if (total_seconds < 0) {
            total_seconds += 24 * 3600;
        }

        // 시간을 다시 시, 분, 초로 나누어 설정
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

//MyClock 내부의 함수 아님. 

std::ostream& operator<<(std::ostream& out, const MyClock& c) {
	out << c.hour() << ":" << c.minute() << ":" << c.second() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, MyClock& c) {
	int h, m, s;
	char delim1, delim2;

	in >> h >> delim1 >> m >> delim2 >> s;

	if (in.fail() || delim1 != ':' || delim2 != ':' || !c.SetTime(h, m, s)) {
		in.setstate(std::ios::failbit); // 실패 상태 설정
	}
	return in; 
}
