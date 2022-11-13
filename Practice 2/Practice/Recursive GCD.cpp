/*#include<iostream>

int GCD(int m, int n) {
	if (m == 1) {
		return 1;
	}
	else if (m == 0 && n == 0) {
		return 0;
	}
	else if (n == 0) {
		return m;
	}
	else if (n % m == 0 && m != n) {
		return m;
	}
	else {
		GCD(m - 1, n);
	}
}

int main() {
	std::cout << GCD(24, 24);
}*/