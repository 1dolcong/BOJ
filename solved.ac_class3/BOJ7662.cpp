#include <iostream>
#include <queue>
#include <map> // ���� ���� key , ���� ������ Value 
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue<ll, vector<ll>, less<ll>> max_q;
		priority_queue<ll, vector<ll>, greater<ll>> min_q;
		map<ll, int> map;
		ll num;
		char command;
		int k;
		int count = 0;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> command >> num;
			if (command == 'I') {
				max_q.push(num);
				min_q.push(num);
				map[num]++;
				count++;
				
			}

			else { //command == 'D'
				if (count) {
					if (num == 1) {
						while (!max_q.empty() && map[max_q.top()] == 0) {
							//cout << "max_q.top()�� �� ::" << map[max_q.top()] << endl;
							//cout << "��� pop �� �� ::" << max_q.top() << endl;
							max_q.pop();
						}
						if (!max_q.empty()) {
							//cout << "pop �� �� ::" << max_q.top() << endl;
							map[max_q.top()]--;
							max_q.pop();
						}
					}
					else {
						while (!min_q.empty() && map[min_q.top()] == 0) {
							//cout << "max_q.top()�� �� ::" << map[max_q.top()] << endl;
							//cout << "pop �� �� ::" << min_q.top() << endl;
							min_q.pop();
						}
						if (!min_q.empty()) {
							//cout << "pop �� �� ::" << min_q.top() << endl;
							map[min_q.top()]--;
							min_q.pop();
						}
					}
					count--;
				}
			}
			
		}

		while (!max_q.empty() && map[max_q.top()] == 0) {
			max_q.pop();
		}
		while (!min_q.empty() && map[min_q.top()] == 0) {
			min_q.pop();
		}

		if (!count) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << max_q.top() << ' ' << min_q.top() << '\n';
		}
	}
}
