#include<iostream>
#include<map>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    map<char, int> word;

    for(char ch : sentence){
        if(isalnum(ch)) word[tolower(ch)]++;
    }
    cout << " ------FREQUENCY OF EACH WORD ---------------" << endl;
    for(auto iter = word.begin(); iter != word.end(); iter++) {
        if(iter->second != 0)
            cout << iter->first << ": " << iter->second << endl;
    }
    return 0;
}