#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 501;
int tc, n, m;
int indegree[MAX];
bool graph[MAX][MAX];

void topologySort()
{
	vector<int> result;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	bool isUnique = true;
	bool cycle = false;

	for (int i = 0; i < n; i++)
	{
		if (q.empty())
		{
			cycle = true;
			break;
		}

		// ������ ���� ����� ���� ������� �ǹ�
		// ���� ����� �����ؾߵ�.
		if (q.size() >= 2)
		{
			isUnique = false;
			break;
		}

		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int j = 1; j <= n; j++)
		{
			// now -> j �� ���� ������ �����Ѵٸ�, now�� ��������
			// �ش� ���� ������ ���ҽ����ش�.
			if (graph[now][j])
			{
				indegree[j]--;
				if (indegree[j] == 0)
					q.push(j);
			}
		}
	}

	// ����Ŭ�� �߻��ߴٴ� ���� ���� ������ ����ȴ�.
	if (cycle)
		cout << "IMPOSSIBLE\n";
	// Ȯ���� ������ �ƴ� ���� ������ ���� ����� ���´ٸ� ��ȣ�ϴ�.
	else if (isUnique == false)
		cout << "?\n";
	else
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << ' ';
		cout << '\n';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> tc;
	while (tc--)
	{
		fill(indegree, indegree + MAX, 0);
		fill(graph[0], graph[0] + MAX * MAX, false);

		cin >> n;
		vector<int> lastRank(n, 0);
		for (int i = 0; i < n; i++) cin >> lastRank[i];

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				// �ڽź��� ���� ��� ���� ��� ����Ų��.
				graph[lastRank[i]][lastRank[j]] = true;
				indegree[lastRank[j]]++;
			}
		}

		cin >> m;
		// ����� ���׵� �ݿ��ϱ�
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			// ���� ���� ������
			if (graph[a][b])
			{
				graph[a][b] = false;
				graph[b][a] = true;
				indegree[a]++;
				indegree[b]--;
			}
			else
			{
				graph[a][b] = true;
				graph[b][a] = false;
				indegree[b]++;
				indegree[a]--;
			}
		}

		topologySort();
	}
	return 0;
}