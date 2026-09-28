#include<functional>
#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, elem;
    cout << "Enter the size of stack: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> elem;
        pq.push(elem);
    }
    
    int k;
    cout << "Enter k: ";
    cin >> k;
    for (int i = 0; i < n; i++) {
        if(i >= n-k)
            cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    return 0;
}