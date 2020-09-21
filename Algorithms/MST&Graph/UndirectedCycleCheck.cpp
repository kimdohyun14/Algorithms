#include <bits/stdc++.h>
using namespace std;

// DisjointSet�� ������ �׷��� �������� ����Ŭ�� �Ǻ��� �� ����� �� �ִ�.
// �� ������ Ȯ���ϸ� �� ����� ��Ʈ ��带 Ȯ���Ѵ�.
// ��Ʈ ��尡 ���� �ٸ��ٸ�, Union ������ �����ϰ�,
// ���ٸ�, ����Ŭ�� �߻��� ���̴�.

// ����� ���� v, ����(union ����)�� ���� e
// ����� ������ �ִ� 100,000����� ����
int v, e;
int parent[100001];

// Ư�� ���Ұ� ���� ������ ã��
int FindParent(int x) {
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	bool cycle = false; // ����Ŭ �߻� ����

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		// ����Ŭ�� �߻��� ��� ����
		if (FindParent(a) == FindParent(b)) {
			cycle = true;
			break;
		}
		// ����Ŭ�� �߻����� �ʾҴٸ� ������(Union)���� ����
		else {
			UnionParent(a, b);
		}
	}

	if (cycle) {
		cout << "����Ŭ�� �߻��߽��ϴ�.\n";
	}
	else {
		cout << "����Ŭ�� �߻����� �ʾҽ��ϴ�.\n";
	}
	return 0;
}