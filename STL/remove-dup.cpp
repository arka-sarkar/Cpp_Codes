#include<iostream>
#include<algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main() {
	vector<int> vec = {13, 44, 23, 44, 34, 23, 44, 44, 23, 23, 12, 13, 13, 13, 13, 44, 34};
	sort(vec.begin(), vec.end());
	auto it = unique(vec.begin(), vec.end());
	vec.resize(distance(vec.begin(), it));
	for(int i: vec) {
	    cout << i << " ";
	}
	cout << endl;
	return 0;
}