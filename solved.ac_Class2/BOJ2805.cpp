#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> v;
	ll N, M; // 나무의 개수, 필요한 나무의 길이
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
		ll result = 0; // 남은 나무 높이
		//cout << "height :: " << height << endl;
		for (ll i = 0; i < N; i++) {
			if (v[i] - height > 0) result += v[i] - height;
		}
		if (result > M) {
			start = height + 1;  
		}
		else if (result < M) {
			end = height - 1;
			if (start > end) { // 조건에서 실패했을 때 못 돌아갈 경우를 대비
				height--;
			}
		}
		else { //result == M
			while (result == M) {
				result = 0;
				height++;
				//cout << "증가 시킨 height :: " << height << endl;

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