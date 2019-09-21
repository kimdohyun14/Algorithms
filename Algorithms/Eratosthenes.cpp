#include <iostream>
using namespace std;

// �Ҽ��� �뷮���� ������ ��Ȯ�ϰ� ���ϴ� �˰���

int a[100001];

void eratosthenes() {
	for (int i = 2; i <= 100000; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= 100000; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= 100000; j += i) {
			a[j] = 0; // �Ҽ��� �ƴϹǷ� �����.
		}
	}
	for (int i = 2; i <= 100000; i++) {
		if (a[i] != 0)
			cout << a[i] << ' ';
	}
}

int main() {
	eratosthenes();
	return 0;
}