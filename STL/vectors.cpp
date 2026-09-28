#include<iostream>
#include<vector>
using namespace std;

template <class T>
void display(vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(i != 0) cout << " ";
        cout << vec.at(i);
    }
    cout << endl;
}

int main() {
    vector<int> vec1;
    vector<char> vec2(4);
    vec2.push_back('5');
    vector<char> vec3(vec2);
    vector<int> vec4(6, 3);
    display(vec1);
    display(vec2);
    display(vec3);
    display(vec4);
    cout << vec1.size() << endl;
    cout << vec2.size() << endl;
    cout << vec3.size() << endl;
    cout << vec4.size() << endl;

    vec1.swap(vec4);
    display(vec1);
    display(vec4);
    cout << vec1.size() << endl;
    cout << vec4.size() << endl;
    
    // int elem, size;
    // cout << "Enter the size of the vector: ";
    // cin >> size;
    // for(int i = 0; i < size; i++) {
    //     cout << "Enter element " << i+1 << ": ";
    //     cin >> elem;
    //     vec1.push_back(elem);
    // }
    // display(vec1);
    // vector<int>::iterator iter = vec1.begin();
    // vec1.insert(iter+2, 2, 566);
    // display(vec1);
    return 0;
}