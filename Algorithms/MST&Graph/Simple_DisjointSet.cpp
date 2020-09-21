#include <bits/stdc++.h>
using namespace std;

// Union ������ ��� a�� ��� b�� ��ģ��. (������)
// Find ������ �ش� ��尡 ��� ���տ� ���� �ִ��� �˷��ش�. (��Ʈ ��带 ��ȯ��)
// �̸� Union-Find �ڷᱸ����� �θ���.
// �ð� ���⵵�� O(V), �־��� ��� Find �Լ��� ��� ��带 �� Ȯ���� ���� �ֱ� �����̴�.

// ����� ���� v�� ����(Union ����)�� ���� e
// ����� ������ �ִ� 100,000����� ����
int v, e;
// �θ� ���̺� �ʱ�ȭ
int parent[100001];

// Ư�� ���Ұ� ���� ������ ã��
int FindParent(int x) {
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
	if (x == parent[x]) return x;
	return FindParent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	// �Ϲ������� �� ��ȣ�� ���� ���Ұ� �θ� ��尡 �ǵ��� �����ϴ� ��찡 ����.
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