#include <bits/stdc++.h>
using namespace std;

// func(a,b,n) n���� ������ a���� b�� �ű�� ����
void func(int a, int b, int n) {
	if (n == 1) { // a�� �ִ� ���� 1���� b�� �ű�⸸ �ϸ� ��
		cout << a << ' ' << b << '\n';
		return;
	}
	int c = 6 - a - b; // a, b�� �ƴ� ������ ����� ��ȣ
	func(a, c, n - 1); // a�� �ִ� 1 to n-1��° ������ a -> c�� �ű�
	cout << a << ' ' << b << '\n'; // a�� �����ִ� n��° ������ b�� �̵�
	func(c, b, n - 1); // c�� �ִ� 1 to n-1��° ������ c -> b�� �ű�
}

int main() {
	func(1, 3, 3);
	return 0;
}