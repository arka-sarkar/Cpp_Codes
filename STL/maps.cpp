#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string, int> marksMap;
    marksMap["Rahul"] = 932;
    marksMap["Vivek"] = 454;
    marksMap["Arka"] = 189;
    marksMap.insert({{"Atul", 556}, {"Arpan", 423}});
    for(auto iter = marksMap.begin(); iter != marksMap.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
    printf("size = %zu\n", marksMap.size());
    printf("max size = %zu\n", marksMap.max_size());
    return 0;
}