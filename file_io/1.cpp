#include<iostream>
#include<fstream>
using namespace std;
/*
Useful classes while working with files in C++ are:

1. fstreambase
2. ifstream --> derived from fstreambase
3. ofstream --> derived from fstreambase
--------------------------------------------------------------
To open a file:

1. Use a constructor
2. Use member function open() of the class
*/
int main() {
    string input;
    fstream in("input.txt", ios_base::app | ios_base::in);

    if(!in) {
        fprintf(stderr, "Error opening file test.txt.\n");
        return 1;
    }

    //in >> input;
    getline(in, input);
    cout << input << endl;
    getline(in, input);
    cout << input << endl;

    in.seekg(0, ios::beg);

    cout << endl;

    getline(in, input);
    cout << input << endl;
    getline(in, input);
    cout << input << endl;
    return 0;
}