#include <bits/stdc++.h>
using namespace std;

int cnt;

// ������ ȣ��Ǵ� ��� �Լ�
// VS ����  ~ 3758 ���� Ȯ��
void RecursionFunction() {
	cout << "��� �Լ� ȣ�� " << cnt++ << '\n';
	RecursionFunction();
}

int main() {
	RecursionFunction();
	return 0;
}