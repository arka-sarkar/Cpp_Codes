#include<iostream> // cout
#include<functional> // container functors
#include<algorithm> // sort
using namespace std;

int main() {
    int arr[] = {1, 2, 6, 2, 5, 5456, 2233, 44, 2, 33, 9, 8};
    cout << size(arr) << endl;
    sort(arr, arr+size(arr), greater_equal());

    for(int i = 0; i < size(arr); i++) {
        if(i != 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}