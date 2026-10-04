#include<cstdint>
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	map<string, int> score;
	int n;
	string winner;
	int total=0;
	cin >> n;
	string names[n];
	int gains[n];
	for (int i = 0; i < n; i++) {
	    cin >> names[i] >> gains[i];
		score[names[i]] += gains[i];
	}

	int maxScore=INT32_MIN;
	for (auto &a : score) {
	    if(a.second > maxScore) maxScore = a.second;
	}

	map<string, int> scoreCopy;
	for (int i = 0; i < n; i++) {
		scoreCopy[names[i]] += gains[i];
		if(score[names[i]]==maxScore && scoreCopy[names[i]]>=maxScore) {
		    winner=names[i];
			break;
		}
	}
	
	cout << winner << endl;
	return 0;
}