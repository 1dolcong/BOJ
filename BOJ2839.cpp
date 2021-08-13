#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int kilo_5 = N / 5;
	int kilo_3 = 0;
	if (N % 5 == 0) {
		cout << kilo_5;
	}
	else { // N % 5 != 0
		int i;
		for (i = kilo_5; i >= 0; i--) {
			kilo_3 = (N - 5 * i) / 3;
			if ((N - 5 * i) % 3 == 0) {
				cout << i + kilo_3;
				break;
			}
		}
		if (i < 0) {
			cout << "-1";
		}
	}

}