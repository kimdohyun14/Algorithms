#include <iostream>
using namespace std;

/*
	# ���μ� ����
	���� ���Ұ� ���� �� ������ ���Ѵ�.
	���� ���� ���踦 �ľ��ϱ� ���ؼ� ���μ� ���� �˰����� ����� �� �ִ�.

	# ���μ� ���� �˰��� (union-find)
	union : 2���� ���Ұ� ���Ե� ������ �ϳ��� �������� ��ġ�� ����
	find  : Ư���� ���Ұ� ���� ������ � �������� �˷��ִ� ����(��Ʈ ��带 ã����)
	��� ���� �ڽ��� ���� ������ ã�� �� ��Ʈ ��带 ��������� ã�´�.
	�� ��, ��� ���� ����� ����ϸ� �� ������ ã�� �� �ִ�.

	# �ð� ���⵵
	����� ���� V, �ִ� V - 1���� union����, M���� find ������ ��
	O(V + MlogV)
*/

int v, e;
int parent[100001];

// Ư�� ���Ұ� ���� ������ ã��
int findParent(int x)
{
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	// ���� �� ���� ���� ��Ʈ ��尡 �ǵ��� ���ش�.
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> v >> e;

	// �θ� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= v; i++) parent[i] = i;

	// union ������ ����
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	// �� ���Ұ� ���� ���� ����ϱ�
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i <= v; i++) cout << findParent(i) << ' ';
	cout << '\n';

	// �θ� ���̺� ���� ����ϱ�
	cout << "�θ� ���̺�: ";
	for (int i = 1; i <= v; i++) cout << parent[i] << ' ';
	cout << '\n';

	return 0;
}