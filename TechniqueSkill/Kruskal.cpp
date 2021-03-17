#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	# ũ�罺Į �˰��� (�ּ� ���� Ʈ�� = MST)
	���� Ʈ�� �߿��� �ּ� ������� ���� �� �ִ� ����Ʈ���� ã�� �˰���
	��� ���ø� '����'�� ��, �ּ����� ������� �����Ϸ��� �� ��

	�ּ� ���� Ʈ���� ������ Ʈ�� �ڷᱸ���̹Ƿ�,
	���� Ʈ���� ���ԵǴ� ������ ������ ����� ���� - 1�� ����.
	V - 1 = E

	# ���� ���
	�ٽ��� ���� �Ÿ��� ª�� �������� ���ʴ�� ���տ� �߰��ϸ� �ȴ�.

	1. ���� �����͸� ��뿡 ���� ������������ �����Ѵ�.
	2. ������ �ϳ��� Ȯ���ϸ� ������ ������ ����Ŭ�� �߻��ϴ��� Ȯ���Ѵ�.
	2-1. ����Ŭ�� �߻����� �ʴ� ��� �ּ� ���� Ʈ���� ���Խ�Ų��.
	2-2. ����Ŭ�� �߻��ϴ� ��� �ּ� ���� Ʈ���� ���Խ�Ű�� �ʴ´�.

	# �ð� ���⵵
	������ ������ E���� ��, O(ElogE)
	�ð��� ���� ���� �ɸ��� �κ��� ������ �����ϴ� �۾��̸�,
	ũ�罺Į ���ο��� ���Ǵ� ���μ� ���� �˰����� �ð� ���⵵�� ���� �˰����� �ð� ���⵵���� �����Ƿ� ����
*/

int v, e;
int parent[100001];
vector<pair<int, pair<int, int> > > edges;
int ans;

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

	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		// ��� ������ �����ϱ� ���ؼ� Ʃ���� ù ��° ���Ҹ� ������� �����Ѵ�.
		edges.push_back({ cost, {a,b} });
	}

	// ������ ��� ������ �����Ѵ�.
	sort(edges.begin(), edges.end());

	// ������ �ϳ��� Ȯ���ϸ鼭 �ּ� ���� Ʈ���� �ϼ���Ų��.
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// ����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ���Խ�Ų��.
		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			ans += cost;
		}
	}

	cout << ans << '\n';
	return 0;
}