#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L; // 알파벳 길이 
int C; // 주어진 문자
vector<char> alphabet;
char vowel[5] = { 'a','e','i','o','u'};
char tempChars[16] = { 0, };

void isRight() {

	int vowelCount = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < L; j++) {
			if (vowel[i] == tempChars[j]) {
				vowelCount++;
			}
		}
	}
	int consonCount = L - vowelCount;
	if (vowelCount > 0 && consonCount > 1) {
		for (int i = 0; i < L; i++) {
			cout << tempChars[i];
		}
		cout << '\n';
	}
}

void search(int tempSize, int index) {
	if (tempSize == L) {
		isRight();
		return;
	}
	if (index == C ) {
		return;
	}
	tempChars[tempSize] = alphabet[index];
	search(tempSize + 1, index + 1);
	search(tempSize, index + 1);

}






int main() {
	cin >> L >> C;
	alphabet.reserve(C);
	char temp = ' ';
	for (int i = 0; i < C; i++) {
		cin >> temp;
		alphabet.push_back(temp);
	}
	sort(alphabet.begin(),alphabet.end());
	search(0, 0);
}