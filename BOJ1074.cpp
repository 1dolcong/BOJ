#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int y, x;

int main() {
	int tableSize;
	cin >> tableSize >> y >> x;
	int realSize = pow(2, tableSize) - 1;  // 0���� ���� �ϱ� ���� 1���� ;
	int progress = tableSize;
	int sum = 0;
	int count = 1;
	for (int i = 0; i < progress; i++) {
		if (realSize / 2 >= y) { //1,2 ��и�
			if (realSize / 2 >= x) { // 1 ��и�
				//cout << "1" << endl;
			}
			else { // 2 ��и� 
				//cout << "2" << endl;
				sum += pow((realSize + 1) / 2, 2) ;
				x -= (realSize+1) / 2;
			}
		}
		else { // 3,4�и� 
			if (realSize / 2 >= x) { // 3 ��и�
				//cout << "3" << endl;
				sum += 2 * pow((realSize + 1) / 2, 2) ;
				y -= (realSize+1) / 2;
			}
			else { //,4 ��и� 
				//cout << "4" << endl;
				sum += 3 * pow((realSize + 1) / 2, 2) ;
				x -= (realSize+1) / 2;
				y -= (realSize+1) / 2;
			}
		}
		
		//cout << count << "������ ���� ���� :: " << sum << endl;
		count++;

		tableSize--;
		realSize = pow(2, tableSize) - 1;
	}

	cout << sum;
}