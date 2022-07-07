#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; cin.ignore();
    string str;
    getline(cin, str);
    char init = 'A';
    map<char,double> operand;
    for (int i = 0; i < n; i++)
    {
        double value; cin >> value;
        operand.insert(make_pair(init++,value));
    }
    int idx = 0;
    stack<double> result;
    for (int i = 0; i < str.size(); i++)
    {
        double operand1, operand2;
        if (str[i] == '*')
        {
            operand2 = result.top();
            result.pop();
            operand1 = result.top();
            result.pop();
            result.push(operand1 * operand2);
        }
        else if (str[i] == '+')
        {
            operand2 = result.top();
            result.pop();
            operand1 = result.top();
            result.pop();
            result.push(operand1 + operand2);
        }
        else if (str[i] == '/')
        {
            operand2 = result.top();
            result.pop();
            operand1 = result.top();
            result.pop();
            result.push(operand1 / operand2);
        }
        else if (str[i] == '-')
        {
            operand2 = result.top();
            result.pop();
            operand1 = result.top();
            result.pop();
            result.push(operand1 - operand2);
        }
        else
        {
            result.push(operand[str[i]]);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result.top();
}
