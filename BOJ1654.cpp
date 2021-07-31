#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int K; // 길이가 각각 다름
int N; // 필요한 렌선

int main() {
	cin >> K >> N;
	vector<int> buffer; // 렌선의 크기는 int 최대값까지 
	buffer.reserve(K);
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		buffer.push_back(temp);
	}
	sort(buffer.begin(), buffer.end());

	ll end = buffer.back(); //int 최대값이라면 
	ll start = 1;
	ll high = -1;
	while (start <= end) {
		ll result = 0;
		ll mid = (start + end) / 2; // 여기서 오버플로 일어날 수도 있다!!
		for (int i = 0; i < K; i++) {
			result += buffer[i] / mid;
		}
		if (result >= N) {
			if (high < mid) {
				high = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}
	cout << high;
}
