#include <iostream>
#include <string>
int alpa[26];
using namespace std;

int main(){
    string str;
    getline(cin,str);
    for(int i=0; i<str.size(); i++){
        int idx = str[i] -'a';
        alpa[idx]++;
    }
    for(int i=0; i<26; i++){
        cout << alpa[i] << ' ';
    }


}

