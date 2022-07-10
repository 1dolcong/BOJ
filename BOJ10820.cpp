#include <iostream>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(getline(cin,str)){
        int lowerCase = 0;
        int upperCase = 0;
        int space = 0;
        int num = 0;

        for(int i=0; i<str.size() ;i++){
            if('a' <= str[i] && str[i] <= 'z') lowerCase++;
            else if('A' <= str[i] && str[i] <= 'Z') upperCase++;
            else if(str[i] == ' ') space++;
            else if( '0' <= str[i] && str[i] <='9') num++;
        }
        cout << lowerCase << ' ';
        cout << upperCase << ' ';
        cout << num << ' ';
        cout << space << endl;
    }


}