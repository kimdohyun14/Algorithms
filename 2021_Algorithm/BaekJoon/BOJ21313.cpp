#include <iostream>
#include <vector>
using namespace std;

// greedy
// ��� ��Ϲ����� �����ϸ� ����.
// ������ ��Ϲ����� ���� ��ȣ�� �޶�� �Ѵ�.
// ���� ó�� ��Ϲ����� ������ ��Ϲ��� ���� �޶���ϹǷ�
// ¦���� 1,2,1,2
// Ȧ���� 1,2,1,2 �ϴٰ� ���������� 3���� ���ָ� ���������� ���� ������.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) 
				cout << "1 ";
			else 
				cout << "2 ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (i % 2 == 0)
				cout << "1 ";
			else
				cout << "2 ";
		}
		cout << "3\n";
	}
	return 0;
}