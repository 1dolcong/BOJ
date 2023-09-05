#include <iostream>
#include <vector>
using namespace std;
int N, M, B; // 가로, 세로, 인벤 
vector<vector<int>> v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> B;
	int min = 257;
	int max = -1;

	v.assign(N,vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] > max) {
				max = v[i][j];
			}
			if (v[i][j] < min) {
				min = v[i][j];
			}
		}
	}
	int bestHeight = 0;
	int bestTime =0x7FFFFFFF;

	for (int h = min ; h <= max; h++) {
		int block_erase_2 = 0;
		int block_insert_1 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int height = h-v[i][j];
				if (height >= 0) {
					block_insert_1 += height;
				}
				else {
					block_erase_2 += -1 * height;
				}
			}
		}
		if (B + block_erase_2 >= block_insert_1) {
			int time = 2 * block_erase_2 + block_insert_1;
			if (time <= bestTime) {
				bestTime = time;
				if (h > bestHeight) {
					bestHeight = h;
				}
			}
		}
	}

	cout << bestTime << ' ' << bestHeight;
}