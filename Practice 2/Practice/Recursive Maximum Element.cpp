/*#include<iostream>

int FindMax(int A[], int n) {
	if (n == 1) {
		return A[0];
	}
	else {
		int curmax = FindMax(A, n - 1);
		if (A[n - 1] > curmax) {
			return A[n - 1];
		}
		else {
			return curmax;
		}
	}
}

int main() {
	int arr[3] = { 9,6,5 };
	std::cout << FindMax(arr, 3);
}*/