#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str; getline(cin, str);
    stack<char> op;
    vector<char> v;
    for(int i=0; i<str.size(); i++){
        if('A'<= str[i] && str[i] <= 'Z'){
            v.push_back(str[i]);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(!op.empty() && op.top()!= '('){
                v.push_back(op.top());
                op.pop();
            }
            op.push(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            while(!op.empty() && op.top()!='('){
                if(op.top()== '*' || op.top()=='/'){   
                    v.push_back(op.top());
                    op.pop();
                }
                else{
                    break;
                }
            }
            op.push(str[i]);
        }
        else if(str[i] == '('){
            op.push(str[i]);
        }
        else if(str[i] == ')'){
            while(op.top() != '('){
                v.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
    }
    while(!op.empty()){
        v.push_back(op.top());
        op.pop();
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
}