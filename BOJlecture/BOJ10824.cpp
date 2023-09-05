#include <iostream>
#include <string>
using namespace std;

int main(){
    string A,B,C,D;
    cin >> A >> B >> C >> D;
    string AB = A + B;
    string CD = C + D;
    cout << stoll(AB) + stoll(CD);

}