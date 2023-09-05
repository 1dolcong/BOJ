#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<char> temp;


void isBalance() {
	bool isBalance = true;
	stack<char> checkBalance;
	for (int i = 0; i < temp.size(); i++) {
		char current = temp[i];
		if (current == '(' || current == ')' || current == '[' || current == ']') {
			if (!checkBalance.empty()) {
				if (current == ')') {
					if (checkBalance.top() == '(') {
						checkBalance.pop();
					}
					else {
						isBalance = false;
						break;
					}
				}
				else if (current == ']') {
					if (checkBalance.top() == '[') {
						checkBalance.pop();
					}
					else {
						isBalance = false;
						break;
					}
				}
				else { // "(", "["
					checkBalance.push(current);
				}
			}
			else { // 아무 것도 없을 때 
				if (current == ']' || current == ')') {
					isBalance = false;
					break;
				}
				checkBalance.push(current);
			}
		}
	}
	if (isBalance && !checkBalance.size()) {
		cout << "yes" << '\n';
	}
	else {
		cout << "no" << '\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> line;
	while (true) {
		temp.clear();
		while (true) {
			char c = getchar();
			if (c != '.') {
				temp.push_back(c);
			}
			else if (c == '\n') continue;
			else {
				break;
			}
		}
		if (temp.size() == 1) {
			break;
		}

		isBalance();
	}

}