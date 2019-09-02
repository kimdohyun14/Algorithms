#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int s;

void add(int x) {
	// s�� x�� �߰��Ѵ�. (�̹� �ִٸ� ����)
	s = s | (1 << x);
}

void remove(int x) {
	// s���� x�� �����Ѵ�. (���� ��� ����)
	s = s & ~(1 << x);
}

int check(int x) {
	// s�� x�� ������ 1��, ������ 0�� ���
	int temp = s & (1 << x);
	if (temp == 0)
		return 0;
	else
		return 1;
}

void toggle(int x) {
	// s�� x�� ������ x�� ����, ������ x�� �߰�
	// �̸��� 1 -> 0, 0 -> 1
	s = s ^ (1 << x);
}

void all() {
	// s�� ��ü �������� �Ѵ�.
	// ��� �ִٰ� ����
	s = (1 << 22) - 1;
}

void empty() {
	// s�� ���������� �ٲ۴�.
	s = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for (int tc = 0; tc < m; tc++) {
		string command;
		int x;
		cin >> command;
		
		if (command[0] == 'a') {
			if (command[1] == 'd') {
				cin >> x;
				add(x);
			}
				
			else {
				all();
			}
				
		}
		else if (command[0] == 'r') {
			cin >> x;
			remove(x);
		}
		else if (command[0] == 'c') {
			cin >> x;
			cout << check(x) << '\n';
		}
		else if (command[0] == 't') {
			cin >> x;
			toggle(x);
		}
		else
			empty();
	}

	return 0;
}