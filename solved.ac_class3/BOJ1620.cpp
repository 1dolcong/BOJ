#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int N, M; // 포켓몬 개수, 내가 맞춰야 하는 문제 개수 
map<string, int> poketmon;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.reserve(N);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string monster;
		cin >> monster;
		poketmon[monster] = i;
		v.push_back(monster);
	}
	for (int i = 0; i < M; i++) {
		string temp;
		int idx = -1;
		bool isInterger = true;
		cin >> temp;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] > '9' && '0' < temp[i] ) {
				isInterger = false;
			}
		}
		if (isInterger) {
			int idx = stoi(temp)-1;
			cout << v[idx] << '\n';
		}
		else {
			cout << poketmon[temp] << '\n';
		}
	}
}