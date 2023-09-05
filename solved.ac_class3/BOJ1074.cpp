#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int y, x;

int main() {
	int tableSize;
	cin >> tableSize >> y >> x;
	int realSize = pow(2, tableSize) - 1;  // 0까지 포함 하기 위해 1빼기 ;
	int progress = tableSize;
	int sum = 0;
	int count = 1;
	for (int i = 0; i < progress; i++) {
		if (realSize / 2 >= y) { //1,2 사분면
			if (realSize / 2 >= x) { // 1 사분면
				//cout << "1" << endl;
			}
			else { // 2 사분면 
				//cout << "2" << endl;
				sum += pow((realSize + 1) / 2, 2) ;
				x -= (realSize+1) / 2;
			}
		}
		else { // 3,4분면 
			if (realSize / 2 >= x) { // 3 사분면
				//cout << "3" << endl;
				sum += 2 * pow((realSize + 1) / 2, 2) ;
				y -= (realSize+1) / 2;
			}
			else { //,4 사분면 
				//cout << "4" << endl;
				sum += 3 * pow((realSize + 1) / 2, 2) ;
				x -= (realSize+1) / 2;
				y -= (realSize+1) / 2;
			}
		}
		
		//cout << count << "까지의 진행 사항 :: " << sum << endl;
		count++;

		tableSize--;
		realSize = pow(2, tableSize) - 1;
	}

	cout << sum;
}