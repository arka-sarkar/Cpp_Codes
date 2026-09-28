#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool compareMarks(const pair<string, int>& pair1,const pair<string, int>& pair2) {
    int marks1 = pair1.second;
    int marks2 = pair2.second;
    return (marks1>marks2);
}

int main() {
	vector<pair<string, int>> vec;
	int n, marks;
	string name;
	cout << "Enter the number of students: ";
	cin >> n;

	for(int i = 1; i <= n; i++) {
	    cout << "Enter name and marks of student " << i << ": ";
		cin >> name >> marks;
		vec.push_back({name, marks});
	}

	sort(vec.begin(), vec.end(), compareMarks);

	cout << "The names and marks of the first 3 best student are: " << endl;
	for(int i = 0; i < 3; i++) {
	    cout << vec.at(i).first << " " << vec.at(i).second << endl;
	}

	return 0;
}
