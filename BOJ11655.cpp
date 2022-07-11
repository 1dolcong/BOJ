#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int len = str.size();
    for(int i=0; i<len; i++){
        if('a' <= str[i]  && str[i] <= 'z'){
           cout << char((str[i] - 'a' + 13 ) % 26 + 'a'); 
        }
        else if( 'A' <= str[i] && str[i] <= 'Z'){
           cout << char((str[i] - 'A' + 13 ) % 26 + 'A');     
        }
        else{
           cout << str[i];
        }
    }

}