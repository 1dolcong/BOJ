#include <iostream>
using namespace std;
typedef long long ll;


ll V; // ���� ���� ����
ll A; // ���� �ö� �� �ִ� ����
ll B; // �㿡 �̲������� ����

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