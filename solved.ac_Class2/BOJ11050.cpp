#include <iostream>
#include <vector>
using namespace std;
int buffer[11][11] = { 0, };
int N;
int K;

void find(int N, int K) {
	if (buffer[N][K] == 0) {
		buffer[N][K] = buffer[N - 1][K] + buffer[N - 1][K - 1];
	}
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= 10; i++) {
		buffer[i][0] = 1;
		buffer[i][1] = i;
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (buffer[i][j]) continue;
			find(i, j);
		}
	}
	cout << buffer[N][K];
}
