#include <iostream>
using namespace std;
int N;

int main() {
	cin >> N;
	int countTwo = 0;
	int countFive = 0;
	for (int i = 1; i <= N; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			countTwo++;
			temp /= 2;
		}
	}
	for (int i = 1; i <= N; i++) {
		int temp = i;
		while (temp % 5 == 0) {
			countFive++;
			temp /= 5;
		}
	}
	int ans;
	if (countTwo < countFive) {
		ans = countTwo;
	}
	else {
		ans = countFive;
	}
	cout << ans;
}