#include <bits/stdc++.h>
using namespace std;

void RecursionFunction(int i) {
	// 5��° ȣ���� ���� �� ����ǵ��� ���� ���� ���
	if (i == 5) return;
	cout << i << "��° ��� �Լ����� " << i + 1 << "��° ����Լ��� ȣ��" << '\n';
	RecursionFunction(i + 1);
	cout << i << "��° ��� �Լ��� �����մϴ�." << '\n';
}

int main() {
	RecursionFunction(1);
	return 0;
}