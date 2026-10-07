#include<cctype>
#include<iostream>
#include<regex>
#include<sstream>
#include<string>
using namespace std;

enum formats { format1, format2 };

string convert(enum formats format, string input) {
    unsigned int row = 0, col = 0;
    string col1;
    ostringstream out;
    istringstream ss(input);
    if(format == format1) {
        for (char ch: input) {
            if(isupper(ch))
                col = col*26 + (ch-'A'+1);
            if(isdigit(ch))
                row = row*10 + (ch-'0');
        }
        out << "R" << row << "C" << col;
    } else if(format == format2) {
        char a, b;
        ss >> a >> row >> b >> col;
        ostringstream col2;
        while (col > 0) {
            if(col%26!=0) {
                col2 << static_cast<char>((col%26)-1+'A');
                col /= 26;
            } else {
                col2 << 'Z';
                col = col/26 - 1;
            }
        }
        col1 = col2.str();
        reverse(col1.begin(), col1.end());
        out << col1 << row;
    }
    return out.str();
}

int main() {
	int n;
	cin >> n;
	string coord[n];
	for (auto &elem: coord) {
	    cin >> elem;
	}
	
	enum formats format[n];
	char ch;
	const regex pattern1("^[A-Z]+[0-9]+$");
	const regex pattern2("^R[0-9]+C[0-9]+$");
	
	for (int i = 0; i < n; i++) {
        if(regex_match(coord[i], pattern1)) format[i] = format1;
        else if(regex_match(coord[i], pattern2)) format[i] = format2;
	}

	for (int i = 0; i < n; i++) {
	    cout << convert(format[i], coord[i]) << endl;
	}
	return 0;
}