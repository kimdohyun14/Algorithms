#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ž�±�
int g, p;
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
	freopen("input.txt", "r", stdin);

	cin >> g >> p;

	for (int i = 1; i <= g; i++) parent[i] = i;

	int cnt = 0;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		int root = findParent(x); // ���� ������� ž�±��� ��Ʈ Ȯ��
		if (root == 0) break;     // ���� ��Ʈ�� 0�̶�� ����
		unionParent(root, root - 1); // �ٷ� ������ ���հ� ��ġ��
		cnt++;
	}

	cout << cnt << '\n';
	return 0;
}