#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;;
ll N,B;
ll base[5][5] = { 0, };
ll cMatrix[5][5] = { 0, };


void calculate(ll X[5][5],ll Y[5][5]) {
	ll tempmatrix[5][5] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ll result = 0;
			for (int k = 0; k < N; k++) {
				result += X[i][k] * Y[k][j];
			}
			tempmatrix[i][j] =result % 1000;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			X[i][j] = tempmatrix[i][j];
		}
	}
}

void pow( ll count) {
while (count > 0) {
		if (count % 2 == 1) {
			calculate(base, cMatrix);
		}
		calculate(cMatrix, cMatrix);
		count /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		base[i][i] = 1;
		for (int j = 0; j < N; j++) {
			cin >> cMatrix[i][j];
		}
	}
	pow(B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << base[i][j]<< ' ';
		}
		cout << endl;
	}
}