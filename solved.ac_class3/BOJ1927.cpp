#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>, greater<ll>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		ll temp;
		cin >> temp;

		if (temp == 0) {
			if (pq.empty()) {
				cout << '0' << '\n';
			}
			else {
				ll t = pq.top();
				pq.pop();
				cout << t << '\n';
			}
		}
		else {
			pq.push(temp);
		}
	}
}