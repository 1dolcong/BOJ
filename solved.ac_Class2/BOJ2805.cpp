#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> v;
	ll N, M; // ������ ����, �ʿ��� ������ ����
	cin >> N >> M;
	v.reserve(N);

	ll tallest = -1;

	for (ll i = 0; i < N; i++) {
		ll temp;
		cin >> temp;
		if (tallest < temp) tallest = temp;
		v.push_back(temp);
	}

	ll start = 0;
	ll end = tallest;
	ll height =0;

	while (start <= end) {
		height = (start + end) / 2;
		ll result = 0; // ���� ���� ����
		//cout << "height :: " << height << endl;
		for (ll i = 0; i < N; i++) {
			if (v[i] - height > 0) result += v[i] - height;
		}
		if (result > M) {
			start = height + 1;  
		}
		else if (result < M) {
			end = height - 1;
			if (start > end) { // ���ǿ��� �������� �� �� ���ư� ��츦 ���
				height--;
			}
		}
		else { //result == M
			while (result == M) {
				result = 0;
				height++;
				//cout << "���� ��Ų height :: " << height << endl;

				for (ll i = 0; i < N; i++) {
					if (v[i] - height > 0) result += v[i] - height;
				}
			}
			height--;
			break;
		}
	}

	cout << height;

}