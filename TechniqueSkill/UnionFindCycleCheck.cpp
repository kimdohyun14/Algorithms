#include <iostream>
using namespace std;

/*
	# ���μ� ������ Ȱ���� ����Ŭ �Ǻ�
	������ �׷��� ������ ����Ŭ�� �Ǻ��� �� ����� �� �ִ�.
	���� �׷����� DFS�� �̿��ؼ� �Ǻ��� �� �ִ�.

	# ���� ���
	1. �� ������ Ȯ���ϸ鼭 �� ����� ��Ʈ ��带 Ȯ���Ѵ�.
	2. ��Ʈ ��尡 �ٸ��ٸ� �� ��忡 ���Ͽ� union ������ ����
	3. ��Ʈ ��尡 ���� ���ٸ� ����Ŭ�� �߻��� ���̴�.
*/

int v, e;
int parent[100001];

int findParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> v >> e;

	for (int i = 1; i <= v; i++) parent[i] = i;

	bool cycle = false; // ����Ŭ �߻� ����
	for (int i = 0; i < e; i++) // �� ������ Ȯ���Ѵ�
	{
		int a, b;
		cin >> a >> b;
		// ����Ŭ�� �߻��� ��� �����Ѵ�.
		// ��, �� ��Ʈ ��尡 ���ٸ� ����Ŭ�� �߻��� ��
		if (findParent(a) == findParent(b))
		{
			cycle = true;
			break;
		}
		else
			unionParent(a, b);
	}

	if (cycle)
		cout << "Cycle!\n";
	else
		cout << "NoCycle!\n";

	return 0;
}