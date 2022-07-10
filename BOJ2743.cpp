#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int len =0; 
    for(int i=0; str[i]; i++){
        len+=1;
    }
    cout <<len;
}