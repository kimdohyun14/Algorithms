#include <iostream>
using namespace std;

int n, m, card = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num = (num == 0) ? 1 : num; // ī�嵦�� ��� ���� �ʾ����� ���������� �ο�
		card = (card * num) % m;    // ���� �ſ� Ŭ �� �ֱ� ������ m���� �����ش�.
	}

	cout << card % m << '\n';
	return 0;
}