#include <bits/stdc++.h>
using namespace std;

// n�� �Է¹޾� n���� 1���� ���ʴ�� ���
void func(int n) {
	cout << n << ' ';
	if (n == 1) return; // base condition;
	func(n - 1);
}

int main() {
	func(5);
	return 0;
}