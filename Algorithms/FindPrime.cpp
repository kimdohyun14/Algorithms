#include <iostream>
using namespace std;

// �ϳ��� ���ڰ� �Ҽ����� �Ǻ��ϴ� �˰���
// �ð� ���⵵ O(N^(1/2))
// 2 * 4 = 4 * 2�� ���� ������ ��Ī�� �̷�� ������
// Ư���� ������ �����ٱ����� ����� ���θ� �����ϸ� �ȴ�.

bool isPrimeNumber(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return true;
}

int main() {
	cout << isPrimeNumber(97);
	return 0;
}