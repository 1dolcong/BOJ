#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int K; // ���̰� ���� �ٸ�
int N; // �ʿ��� ����

int main() {
	cin >> K >> N;
	vector<int> buffer; // ������ ũ��� int �ִ밪���� 
	buffer.reserve(K);
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		buffer.push_back(temp);
	}
	sort(buffer.begin(), buffer.end());

	ll end = buffer.back(); //int �ִ밪�̶�� 
	ll start = 1;
	ll high = -1;
	while (start <= end) {
		ll result = 0;
		ll mid = (start + end) / 2; // ���⼭ �����÷� �Ͼ ���� �ִ�!!
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
