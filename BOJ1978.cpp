#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) continue;
		bool isPrime = true; 
		for (int i = 2; i <= (int)sqrt(temp); i++) { // 2부터 나눠야 한다..
			if (temp % i == 0) isPrime = false;
		}
		if (isPrime) cnt++;
	}
	cout << cnt;
}
