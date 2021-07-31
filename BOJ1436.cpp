#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	string six = "666";
	int cnt = 0;
	int num = 0;
	while (cnt < N) {
		if (to_string(num).find(six) != string::npos) {
			cnt++;
		}
		num++;
	}
	cout << num-1;
}
