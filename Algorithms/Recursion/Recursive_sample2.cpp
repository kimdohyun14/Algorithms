#include <bits/stdc++.h>
using namespace std;

// n�� �Է� �޾� n���� 1���� ���� ��� n!
int func(int n) {
	if (n == 1) return 1; // base condition
	return n * func(n - 1);
}

int main() {
	cout << func(5);
	return 0;
}