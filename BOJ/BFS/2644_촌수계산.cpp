#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, s, e, cycle;
vector<int> a[101];
bool visited[101];
int dist[101];

bool bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < a[cur].size(); i++)
		{
			int neighbor = a[cur][i];

			if (visited[neighbor] == false)
			{
				dist[neighbor] = dist[cur] + 1; // �̼� ����
				visited[neighbor] = true;
				q.push(neighbor);
				if (neighbor == end) // ���࿡ ���� ã�� �̿��̶��?
				{
					return true;
				}
			}
		}
	}

	return false; // �̼��� ���谡 �ƴ϶��
}

int main()
{
	cin >> n;       // �� �����
	cin >> s >> e;  // �� ����� ���踦 �� ���ϱ�?
	cin >> cycle;   // ���� �� 
	for (int i = 0; i < cycle; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	bool ret = bfs(s, e);
	if (ret)
		cout << dist[e];
	else
		cout << -1;

	return 0;
}