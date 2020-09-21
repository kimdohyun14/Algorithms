#include <bits/stdc++.h>
using namespace std;

// DisjointSet (���μ� ����)
// Find �Լ����� ��� ���� ����� �̿��ϸ� �� ������ ������ �� �ִ�.
// ����� ������ V��, �ִ� V - 1���� Union ����� M���� Find ������ ������ ��,
// �ð� ���⵵ O(V + MlogV)

int v, e;
int parent[100001];

int FindParent(int x) {
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
	if (x == parent[x]) return x;
	// ��� ���� ���
	// �� ��忡 ���Ͽ� find �Լ��� ȣ���� ���Ŀ�, �ش� ����� ��Ʈ ��尡 �ٷ� �θ� ��尡 �ǵ���
	return parent[x] = FindParent(parent[x]);
}

void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	// �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// Union ������ ���� ����
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		UnionParent(a, b);
	}

	// �θ� ���̺� ���� ����ϱ�
	cout << "�θ� ���̺�: ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << ' ';
	}
	cout << '\n';

	// ��ξ����� �ҷ���, ��ü������ Find ������ �� �� �� ����� �Ѵ�.
	// �� ���Ұ� ���� ���� ����ϱ�
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i <= v; i++) {
		cout << FindParent(i) << ' ';
	}
	cout << '\n';

	// �θ� ���̺� ���� ����ϱ�
	cout << "�θ� ���̺�: ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << ' ';
	}
	cout << '\n';
	return 0;
}