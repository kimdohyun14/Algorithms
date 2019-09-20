#include <iostream>
using namespace std;

// ������ �Ǻ���ġ ������ ���� ��
// �޸������̼��� �̿��ؼ� ���̳��� ���α׷��� ����� �����Ű��.
// �ð� ���⵵ O(N)
// ���̳��� ���α׷����� ��� ������ 1������ Ǭ��.
// ��� ���� * 1������ Ǫ�� �ð�
// N�� ȣ�� * O(1)
// O(N)
int memo[100];

int fibonacci(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (memo[x] != 0) return memo[x]; // �̹� ���� Ǯ���ٸ� �� ���� ��ȯ
	return memo[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
	cout << fibonacci(10) << '\n';
	cout << fibonacci(30) << '\n';
	//cout << fibonacci(50) << '\n'; �����÷ο� (int���� �����)
	return 0;
}