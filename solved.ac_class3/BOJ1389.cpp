#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
bool person[101][101];
bool isVisit[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		person[A][B] = true;
		person[B][A] = true;
	}
	int BestKebin = 10000;
	int bestPerson = -1;
	for (int i = 1; i <= N; i++) {
		int kebin = 0;
		queue<pair<int,int>> destination; // 행선지, count 수 
		destination.push(make_pair(i, 0));
		while (!destination.empty()) {
			int from = destination.front().first;
			int count = destination.front().second;
			kebin += count;
			destination.pop();
			isVisit[from] = true;
			for (int j = 1; j <= N;j++) {
				if (person[from][j] && !isVisit[j]) {
					destination.push(make_pair(j, count + 1));
				}
			}
		}
		if (kebin < BestKebin) {
			BestKebin = kebin;
			bestPerson = i;
		}
		for (int k = 1; k <= N; k++) {
			isVisit[k] = false;
		}
	}
	cout << bestPerson;
}