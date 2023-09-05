#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

list<int> container;
int N, K;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		container.push_back(i);
	}
	list<int>::iterator it = container.begin();
	cout << "<";
	while (!container.empty()) {
		for (int i = 1; i < K; i++) {
			if (*it == container.back()) {
				it = container.begin();
			}
			else {
				it++;
			}
		}
		if (container.front() != container.back()) {
			cout << *it << ", ";
		}
		else {
			cout << *it;
		}

		if (*it == container.back()) {
			it = container.begin();
			container.pop_back();
		}
		else {
			it = container.erase(it);
		}
	}
	cout << ">";
}