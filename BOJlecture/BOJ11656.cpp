#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string s1, const string s2){
    return s1<s2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    string str;
    getline(cin, str);
    int len = str.size();
    v.reserve(len);
    for(int i=0; i<len; i++){
        v.push_back(str.substr(i));
    }
    sort(v.begin(),v.end(),cmp);
    for(vector<string>::iterator it= v.begin(); it!=v.end(); ++it){
        cout << *it << endl;
    }
}