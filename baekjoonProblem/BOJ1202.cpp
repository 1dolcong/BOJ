#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N, K; // N: 보석의 수, K: 가방의 수  
vector<pair<int, int>> jwelry; // 무게 , 가격
multiset<int> bag;
unsigned long long result = 0;

typedef struct jwelryCompare { // 
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
} jwelryCompare;


void robbing() {
	for (int i = 0; i < N; i++) { //보석을 가방에 넣을 때
		auto iter = bag.lower_bound(jwelry[i].first);
		if (iter != bag.end()) {
			bag.erase(iter);
			result += jwelry[i].second;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	jwelry.reserve(N);
	for (int i = 0; i < N; ++i) {
		int weight =0;
		int value =0;
		cin >> weight >> value;
		jwelry.push_back(make_pair(weight, value));
	}
	for (int j = 0; j < K; ++j) {
		int temp;
		cin >> temp;
		bag.insert(temp);
	}
	sort(jwelry.begin(), jwelry.end(), jwelryCompare());
	robbing();
	cout << result;
}