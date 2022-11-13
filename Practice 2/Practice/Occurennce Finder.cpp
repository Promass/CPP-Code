/*#include<iostream>
#include<array>

using namespace std;

void insertionsort(array<int, 10> &a, int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

array<int, 11> gradefinder(array<int, 10> &a, int n) {
	insertionsort(a, n);

	int occurnbr = 1;
	int currentoccur = 1;
	int currentgrade = a[0];
	int resultidx = 0;
	array<int, 11> result;

	for (int idx = 1; idx <= n; idx++) {
		if (idx == n) {
			if (currentoccur > occurnbr) {
				occurnbr = currentoccur;
				for (int j = 0; j <= resultidx; j++) {
					result[j] = null;
				}
				resultidx = 0;
				result[resultidx] = currentgrade;
				resultidx += 1;
			}
			else if (currentoccur == occurnbr) {
				result[resultidx] = currentgrade;
				resultidx++;
			}
			continue;
		}

		if (currentgrade == a[idx]) {
			currentoccur += 1;
			continue;
		}
		else {
			if (currentoccur > occurnbr) {
				occurnbr = currentoccur;
				for (int j = 0; j <= resultidx; j++) {
					result[j] = null;
				}
				resultidx = 0;
				result[resultidx] = currentgrade;
				resultidx += 1;
			}
			else if (currentoccur == occurnbr) {
				result[resultidx] = currentgrade;
				resultidx++;
			}
		}
		currentoccur = 1;
		currentgrade = a[idx];
	}

	result[resultidx] = occurnbr;

	return result;
}

int main() {
	array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

	array<int, 11> arr2 = gradefinder(arr, 10);

	for (int idx = 0; idx < 11; idx++) {
		cout << arr2[idx] << endl;
	}
}*/