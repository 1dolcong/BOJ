#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> chessboard;

int N, M;
char chess1[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
char chess2[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};
int findChange(int y, int x) {
	int result1 = 0;
	int result2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess1[i][j] != chessboard[y+i][x+j] ) {
				result1++;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess2[i][j] != chessboard[y + i][x + j]) {
				result2++;
			}
		}
	}
	return result1 < result2 ? result1 : result2;
}



int main() {
	cin >> N >> M;
	chessboard.assign(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chessboard[i][j];
		}
	}
	int answer = 2501;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int temp = findChange(i, j);
			if (answer > temp) {
				answer = temp;
			}
		}
	}
	cout << answer;
}
