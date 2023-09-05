#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    vector<int> result;
    stack<int> s;
    v.reserve(n);
    v.assign(n,0);
    result.reserve(n);
    result.assign(n,0);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++){
        while(!s.empty() && v[s.top()] < v[i]){
                result[s.top()] = v[i];
                s.pop();
            }
            s.push(i);
        }
    
    while(!s.empty()){
        result[s.top()] = -1;
        s.pop();
    }

    for(int i=0; i<n; i++){
        cout << result[i] << ' ';
    }
}
   


 