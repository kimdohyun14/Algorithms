#include <iostream>
using namespace std;

// ������(Union-Find)�� �����غ���.
// ���� ���� ��尡 ������ ��, �� ���� ��带 �����ؼ�
// ���� �ΰ��� ��尡 ���� ���� �׷����� �����ִ��� �Ǻ��ϴ� �˰���

// �θ� ��带 ã�� �Լ�
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ� (Union)
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	// �� �θ� ��带 ��ĥ ���� �� ���� ������ ��ģ��.
	// ��Ʈ ��尡 ���� ��忩�� �Ѵ�. (�Ϲ�������)
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ�� (Find)
// (���� �׷����� �� ��尡 �����ִ���)
bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	else return false;
}

int main() {
	int parent[11];
	// ó������ ��� ������ �ڱ� �ڽ��� ����Ű���� �����.
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	
	// �׷������� ��� ����Ǿ� �ִ��� union���� ���Ἲ�� ǥ��.
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	// �� ��尡 ���� �׷����� �����ִ��� find�� Ȯ���غ���.
	cout << "1�� 5�� ����Ǿ� �ֳ���? : ";
	if (findParent(parent, 1, 5)) {
		cout << "��" << '\n';
	}
	else {
		cout << "�ƴϿ�" << '\n';
	}

	cout << "1�� 5�� �������ݴϴ�." << '\n';
	unionParent(parent, 1, 5);

	cout << "1�� 5�� ����Ǿ� �ֳ���? : ";
	if (findParent(parent, 1, 5)) {
		cout << "��" << '\n';
	}
	else {
		cout << "�ƴϿ�" << '\n';
	}

	cout << "2�� 8�� ����Ǿ� �ֳ���? : ";
	if (findParent(parent, 2, 8)) {
		cout << "��" << '\n';
	}
	else {
		cout << "�ƴϿ�" << '\n';
	}
	return 0;
}