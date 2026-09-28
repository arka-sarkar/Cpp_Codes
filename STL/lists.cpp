#include<iostream>
#include<list>
using namespace std;

template<class T>
void display(list<T>& l) {
    auto iter = l.begin();
    for(;iter != l.end(); iter++) {
        if(iter != l.begin()) cout << " ";
        cout << *iter;
    }
    cout << endl;
}

int main() {
    list<int> list1;
    list1.push_back(3);
    list1.push_back(4);
    list1.push_front(5);
    list1.push_back(3);
    list1.push_back(-1);
    display(list1);
    list1.sort();
    display(list1);
    return 0;
}