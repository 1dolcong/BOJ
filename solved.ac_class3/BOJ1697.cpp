#include <iostream>
#include <algorithm>
using namespace std;
int DP[200000];
int N, K;


int main() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		DP[i] = N-i;
	}

	for (int i = N+1; i <= K; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) {
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
		else {
			DP[i] = min(DP[i], DP[(i + 1) / 2] + 2);
		}
	}

	cout << DP[K];
}