/*#include<iostream>

int RepFinder(int A[], int n, int idx) {
	int currentidx = idx - n;

	if (n == 0) {
		return NULL;
	}
	else {
		if (A[currentidx - 1] == A[currentidx]) {
			return A[currentidx];
		}
		else {
			RepFinder(A, n - 1, n+1);
		}
	}
}

int main() {
	int arr[8] = { 1,8,5,4,2,1,7,6 };
	std::cout << RepFinder(arr, 8, 9);
}*/