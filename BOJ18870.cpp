#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; 
	cin >> N;
	vector<int> order;
	set<int> s;
	map <int, int> m;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		order.push_back(temp);
		s.insert(temp);
	}
	int idx =0;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		m[*it] = idx++;
	}

	for (int i = 0; i < N; i++) {
		cout << m[order[i]] << ' ';
	}
}