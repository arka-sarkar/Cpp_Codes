#include<sstream>
#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

class Time {
    int hours, minutes, seconds;

    public:
        Time(int h, int m, int s) {
            seconds = s%60;
            minutes = m+s/60;
            hours = h + minutes/60;
            minutes %= 60;
        }

        static Time addTime(Time& time1, Time& time2);

        friend ostream& operator<<(ostream& out, const Time& time) {
            out << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
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
    getline(ss, token, ':');
    int hours = stoi(token);

    getline(ss, token, ':');
    int minutes = stoi(token);

    getline(ss, token);
    int seconds = stoi(token);
    return Time(hours, minutes, seconds);
}

int main() {
	try{
	    string time1, time2;
		cin >> time1 >> time2;
        auto time_obj1 = parseTime(time1);
        auto time_obj2 = parseTime(time2);
        cout << Time::addTime(time_obj1, time_obj2);
	} catch(invalid_argument) {
	    cout << "Invalid input." << endl;
	}
	return 0;
}