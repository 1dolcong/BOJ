#include <iostream>
using namespace std;
int container[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		container[temp]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < container[i]; j++) {
			cout << i << '\n';
		}
	}


}