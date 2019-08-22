#include <iostream>
using namespace std;

int a[10001]; // �����ѹ��� 0�̰�, �ƴ϶�� 1�̴�.

void SelfNumber(int number) {
	// d(75) = 75 + 7 + 5 = 87
	// d(n) = n + (n�� �� �ڸ���)
	int sum = number;
	while (number) {
		sum += number % 10;
		number /= 10;
	}

	// ����� 10000���� ������ �� ���ڴ� �����ڰ� �ִٴ� ��
	if (sum < 10000)
		a[sum] = 1;
}

int main() {
	// ���� d(n)�� �� ���Ѵ�.
	for (int i = 1; i <= 10000; i++) {
		SelfNumber(i);
	}

	// ���߿��� 0�� �κ��� �����ѹ��̹Ƿ� ����Ѵ�.
	for (int i = 1; i <= 9999; i++) {
		if (a[i] == 0) {
			cout << i << '\n';
		}
	}
	return 0;
}