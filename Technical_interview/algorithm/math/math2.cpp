#include <iostream>
using namespace std;

int main() {
	int num1 = 1e9; // 10��
	int num2 = 2e9; // 20��
	cout << num1 << '\n';
	cout << num2 << '\n';

	// �켱���� ����
	int mask = 1;
	// == �������� �켱���� > &�������� �켱���� => ��� �׻� ����
	if (mask & 1 == 0) {
		// do something
	}
	return 0;
}