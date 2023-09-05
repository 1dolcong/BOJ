#include <iostream>
#include <vector>
using namespace std;
vector<int> buffer;

int findPivot(int start, int end) {
	int pivotValue = buffer[(start + end) / 2];

	while (start < end) { // [start,end]
		while (buffer[start] < pivotValue && start <end) start++;
		while (buffer[end] > pivotValue && start<end)  end--;
		if (start < end) {
			int temp = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = temp;
		}
	}
	return end;
}

void insertionSort(int start, int end) {
	for (int i = start+1; i <= end; i++) {
		int temp = buffer[i];
		int j = i;
		while (j > start && temp < buffer[j-1]) {
			buffer[j] = buffer[j - 1];
			j--;
		}
		buffer[j] = temp;
	}
}


void quickSort(int start, int end) {
	if (start < end) {
		if (end - start > 10) {
			int pivot = findPivot(start, end);
			quickSort(start, pivot - 1);
			quickSort(pivot + 1, end);
		}
		else {
			insertionSort(start, end);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	buffer.reserve(N);
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		buffer.push_back(temp);
	}
	quickSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << buffer[i] << '\n';
	}

}