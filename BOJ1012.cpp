#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int T;
int ground[50][50];
int M,N,K; // 가로 길이 , 세로 길이 , 개수 
bool isVisited[50][50];
vector<pair<int, int>> direction = { {1,0} , {-1,0}, {0,1}, {0,-1} };


void dfs() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<pair<int, int>> s;
	int space = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == 0 || isVisited[i][j] == true) continue;
			s.push(make_pair(i, j));
			while (!s.empty()) { 
				int y = s.top().first;
				int x = s.top().second; 
				isVisited[y][x] = true;
				//cout << "현재 :: " << y << " , " << x << endl;

				s.pop();

				for (int i = 0; i < 4; i++) {
					int temp_y = direction[i].first + y;
					int temp_x = direction[i].second + x;
					if (0 <= temp_y && temp_y < N) {
						if (0 <= temp_x && temp_x < M) {
							if (ground[temp_y][temp_x] == 1 && isVisited[temp_y][temp_x] == false) {
								s.push(make_pair(temp_y, temp_x));
								//cout << "push 되는 수 :: " << temp_y << " , " << temp_x << endl;
							}
						}
					}
				}
			}
			space++;
		}
	}
	cout << space << '\n';
}





int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int i = 0; i < 50; i++) { // 초기화 
			for (int j = 0; j < 50; j++) {
				ground[i][j] = 0;
				isVisited[i][j] = false;
			}
		}
		cin >> M >> N >>K;
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			ground[Y][X] = 1;
		}
		dfs();
	}
}