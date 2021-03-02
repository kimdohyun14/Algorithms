#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	# ���� ����(TopologySort)
	������ ������ �ִ� �Ϸ��� �۾��� ���ʴ�� �����ؾ� �� �� ����ϴ� �˰���

	# �ð� ���⵵
	���ʴ�� ��� ��带 Ȯ���ϸ鼭, �ش� ��忡�� ����ϴ� ������ ���ʴ�� �����ؾ� �ϱ� ������
	O(V + E), V : ����� ��, E : ������ ��
*/

int v, e;
int indegree[100001];
vector<int> graph[100001];

void topologySort()
{
	vector<int> ret; // ���� ���� ���� ����� ���� �迭
	queue<int> q;

	// ó�� ������ ���� ���������� 0�� ������ ť�� �����Ѵ�.
	for (int i = 1; i <= v; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		ret.push_back(now);

		// �ش� ���ҿ� ����� ������ ������������ 1 ����
		for (int i = 0; i < graph[now].size(); i++)
		{
			indegree[graph[now][i]]--;
			// ���Ӱ� ���������� 0�� �Ǵ� ������ ť�� �����Ѵ�.
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	// ���� ������ ������ ����� ����Ѵ�.
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> v >> e;

	// ���� �׷����� ��� ������ ������ �Է¹޴´�.
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // a -> b
		indegree[b]++; // �������� �߰�
	}

	// �������� ����
	topologySort();
	return 0;
}