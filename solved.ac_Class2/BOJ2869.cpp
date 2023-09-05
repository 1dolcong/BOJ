#include <iostream>
using namespace std;
typedef long long ll;


ll V; // 나무 막대 높이
ll A; // 낮에 올라갈 수 있는 높이
ll B; // 밤에 미끄러지는 높이

int main() {
	cin >> A >> B >> V;
	ll present = 0;
	ll period;
	V -= A;
	if (V> 0) {
		if (V % (A - B) != 0) {
			period = V / (A - B) + 1;
		}
		else {
			period = V / (A - B);
		}

		cout << 1 + period;
	}
	else {
		cout << 1;
	}
}