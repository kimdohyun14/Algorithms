#include <bits/stdc++.h>
using namespace std;

int n = 1260;
int cnt = 0;
int coinTypes[] = { 500,100,50,10 };

// ���� ū ������ ���� ������ ��� �����̹Ƿ�, �׸��� ����

int main() {
	// '���� ū ȭ�� ��������' ���� �Ž��� �ִ� ��
	for (int i = 0; i < 4; i++) {
		int coin = coinTypes[i];
		cnt += n / coin;
		n %= coin;
	}
	cout << cnt << '\n';
	return 0;
}