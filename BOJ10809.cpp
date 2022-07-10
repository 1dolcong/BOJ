#include <iostream>
#include <string>
using namespace std;
int apl[26];

int main(){
    for(int i=0; i<26; i++){
        apl[i] = -1;
    }
    string str;
    getline(cin,str);
    for(int i=0; i < str.size(); i++){
        int idx = str[i] -'a';
        if(apl[idx] == -1){
            apl[idx] = i;
        } 
    }
    
    for(int i=0; i<26; i++){
        cout << apl[i] << ' ';
    }
    
}