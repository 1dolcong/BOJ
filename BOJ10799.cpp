#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    stack<char> st1;
    int sum = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            st1.push(s[i]);
        }
        else{
            if(s[i-1] == '('){
                sum += st1.size()-1;
            }
            else{
                sum++;
            }
            st1.pop();
        }
    }
    cout << sum;
}