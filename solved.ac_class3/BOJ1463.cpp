#include <iostream>
#include <algorithm>
using namespace std;
int DP[1000001];

int main() {
	int N;
	cin >> N;
	DP[1] = 0;
	DP[2] = 1;
	for (int i = 3; i <= N; i++) {
		int divided_2 = 1000001;
		int divided_3 = 1000001;
		if (i % 2 == 0) {
			divided_2 = DP[i/2] +1;
		}
		if (i % 3 == 0) {
			divided_3 = DP[i / 3] + 1;
		}
		int divided_ = min(divided_2, divided_3);
		DP[i] = min(DP[i - 1] + 1, divided_);
	}
	cout << DP[N];
}