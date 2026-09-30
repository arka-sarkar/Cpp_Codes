#include<sstream>
#include<iostream>
#include<stdexcept>
#include<string>
#include<iomanip>
using namespace std;

bool isInteger(const string& s) {
    try {
        size_t pos;
        stoi(s, &pos);
        return pos == s.size();   // ensure the ENTIRE string was consumed, not just a prefix
    } catch (...) {
        return false;
    }
}

class Time {
    int hours, minutes, seconds;

    public:
        Time(int h, int m, int s) {
            seconds = s % 60;
            minutes = m + s/60;
            hours = h + minutes/60;
            minutes %= 60;
        }

        static Time addTime(Time& time1, Time& time2);

        friend ostream& operator<<(ostream& out, const Time& time) {
            out << time.hours << ":" << setw(2) << setfill('0') << time.minutes << ":" << setw(2) << setfill('0') << time.seconds;
            return out;
        }
};

Time Time::addTime(Time &time1, Time &time2) {
    int hr = time1.hours + time2.hours;
    int min = time1.minutes + time2.minutes;
    int sec = time1.seconds + time2.seconds;
    return Time(hr, min, sec);
}

Time parseTime(string time) {
    stringstream ss(time);
    string token;
    int _time[3]={0};

    for (int i = 0; i <= 1; i++) {
        getline(ss, token, ':');
        if(!isInteger(token)) throw invalid_argument("Put numbers in h, m, s field for time.");
        _time[i] = stoi(token);
    }
    
    getline(ss, token, ':');
    if(!isInteger(token)) throw invalid_argument("Put numbers in h, m, s field for time.");
    _time[2] = stoi(token);

    for(int i = 0; i < 3; i++) {
        if(_time[i] < 0) throw invalid_argument("Put positive numbers in h, m, s field for time.");
    }

    return Time(_time[0], _time[1], _time[2]);
}

int main() {
	try{
	    string time1, time2;
		cin >> time1 >> time2;
        auto time_obj1 = parseTime(time1);
        auto time_obj2 = parseTime(time2);
        cout << Time::addTime(time_obj1, time_obj2) << endl;
	} catch(const invalid_argument& e) {
	    cout << e.what() << endl;
	}
	return 0;
}