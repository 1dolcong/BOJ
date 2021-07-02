#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int lab[8][8] = { 0, };
int N, M; // 세로 N, 가로 M 
int bestSpace = 0;


//상,좌,우,하
vector<pair<int, int>> dirction{ // 세로, 가로 
make_pair(-1,0), make_pair(0,-1),make_pair(0,1),make_pair(1,0)
};

void spread() {
	queue<pair<int, int>> BFS;
	int templab[8][8] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			templab[i][j] = lab[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (templab[i][j] == 2) {
				BFS.push(make_pair(i, j)); // 2가 되는 것들 미리 넣어두기 
			}
		}
	}
	while (!BFS.empty()) {
		int y = BFS.front().first;
		int x = BFS.front().second;
		BFS.pop();
		for (int i = 0; i < dirction.size(); i++) {
			int ny = y + dirction[i].second;
			int nx = x + dirction[i].first;
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (templab[ny][nx] == 0) {
					templab[ny][nx] = 2;
					BFS.push(make_pair(ny, nx));
				}
			}
		}
	}
	int safespace = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (templab[i][j] == 0) {
				safespace++;
			}
		}
	}
	if (bestSpace < safespace) {
		bestSpace = safespace;
	}
}



int recursiveCount;
void blockLab(int block) {
	if (block == 3) {
		spread();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { // 같은 위치의 111  이라도 1을 적는 순서가 다름으로 중복해서 나옴;; 
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				blockLab(block + 1);
				lab[i][j] = 0;

			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
		}
	}
	blockLab(0);
	cout << bestSpace;
}		