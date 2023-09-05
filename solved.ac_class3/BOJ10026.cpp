#include <iostream>
#include <stack>
using namespace std;
int N; 
// ���ϻ���
char table[100][100];
bool isVisited[100][100];
stack<pair<int, int>> q;


pair<int, int> direction[4] = { {-1,0},{1,0},{0,-1},{0,1} }; // �����¿�

void isRGB_PossibleDirection(int& y, int& x,const int& idx, char& color, int& mode ) {
	int temp_y = y + direction[idx].first;
	int temp_x = x + direction[idx].second;
	//cout << "temp_y�� temp_x  :: " << temp_y << "  " << temp_x << endl;
	if (0 <= temp_y && temp_y < N) {
		if (0 <= temp_x &&  temp_x < N) { // �������� ������ ��
			if (!isVisited[temp_y][temp_x]) { // �ȵ鸰 ���� �� 
				char checkColor = table[temp_y][temp_x];
				if (mode == 0) { //���� 
					if (color == 'R' || color == 'G') {
						if (checkColor == 'R' || checkColor == 'G') {
							q.push(make_pair(temp_y, temp_x));
							//cout << "queue�� �ִ� �� :: " << temp_y << "  " << temp_x << endl;
						}
					}
					else { // 'B' �� �� 
						if (checkColor == 'B') {
							q.push(make_pair(temp_y, temp_x));
							//cout << "queue�� �ִ� �� :: " << temp_y << "  " << temp_x << endl;
						}
					}

				}
				else {
					if (color == checkColor) {
						q.push(make_pair(temp_y, temp_x));
						//cout << "queue�� �ִ� �� :: " << temp_y << "  " << temp_x << endl;
					}
				}
			}
		}
	}
}

void RGB_spread(int& y, int& x, int& mode) {
	char color = table[y][x];
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int present_x = q.top().second;
		int present_y = q.top().first;
		isVisited[present_y][present_x] = true;
		//cout << "���� �鸰 �� ::" << " [" << present_y << "]" << "[" << present_x << "]" << endl;
		q.pop();
		isRGB_PossibleDirection(present_y, present_x, 0, color, mode);
		isRGB_PossibleDirection(present_y, present_x, 1, color, mode);
		isRGB_PossibleDirection(present_y, present_x, 2, color, mode);
		isRGB_PossibleDirection(present_y, present_x, 3, color, mode);
	}
}

void DFS(int mode) {
	int space = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << "���� ��Ȳ :: " << i << " " << j << endl;
			if (isVisited[i][j]) continue;
			RGB_spread(i, j, mode);
			space++;
			//cout << "space :: " << space << endl;
		}
	}
	cout << space << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isVisited[i][j] = false;
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}

	DFS(1);
	DFS(0);
}