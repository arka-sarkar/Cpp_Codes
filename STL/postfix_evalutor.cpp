#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

bool parseNumber(const string& s, double& value) {
    try {
        size_t pos;
        value = stod(s, &pos);
        return pos == s.size();   // whole token must be consumed
    } catch (const exception&) {    // invalid_argument or out_of_range
        return false;
    }
}

int main() {
    stack<double> stck;
    string input;
	getline(cin, input);
	stringstream ss(input);
	double a, b, value;
	string token;

	while (ss >> token) {
        if(parseNumber(token, value)) {
            stck.push(value);
            continue;
        } else if(token == "+" || token == "-" || token == "*" || token == "/") {
            if (stck.size() < 2) {
                cout << "Insufficient operands." << endl;
                return 0;
            }
            b = stck.top();
            stck.pop();
            a = stck.top();
            stck.pop();
        } 

        if(token == "+") {
            stck.push(a+b);
        } else if(token == "-") {
            stck.push(a-b);
        } else if(token == "*") {
            stck.push(a*b);
        } else if(token == "/") {
            if(b != 0) stck.push(a/b);
            else {
                cout << "Division by zero." << endl;
                return 0;
            }
        } else {
            cout << "Invalid operation." << endl;
            return 0;
        }
	}
	if(stck.size() == 1)
	    cout << stck.top() << endl;
	else
	    cout << "Something is wrong with the input." << endl;
	return 0;
}