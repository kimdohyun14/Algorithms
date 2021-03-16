#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
	# ���ͽ�Ʈ�� �˰���
	Ư���� ��忡�� ����Ͽ� �ٸ� ��� ���� ���� ������ �ִ� ��θ� �����ִ� �˰���

	# ���� ���
	1. ��� ��带 ����
	2. �ִ� �Ÿ� ���̺��� �ʱ�ȭ
	3. �湮���� ���� ��� �߿��� �ִ� �Ÿ��� ���� ª�� ��带 �����Ѵ�.
	4. �ش� ��带 ���� �ٸ� ���� ���� ����� ����Ͽ� �ִ� �Ÿ� ���̺��� �����Ѵ�.

	# �ð� ���⵵
	O(ElogV)
	�켱���� ť���� ���� ���� ����� �ٸ� ������ Ȯ���ϴ� �� Ƚ���� �ִ� ������ ���� E��ŭ ����
	�ִ� E���� ���� �����͸� ���� �־��ٰ� ���� ���̹Ƿ� O(ElogE)
	
	�ߺ� ������ �������� �ʴ� ���, E�� �׻� V^2���� �۴�.
	���� E�� �׻� V^2 �����̹Ƿ� ��ü �ð� ���⵵�� O(ElogV)
*/

const int INF = 1e9;

int n, m, start; // ���, ����, ���� ���
vector<pair<int, int>> graph[100001];
int dist[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq; // (���, ���)
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// ���� ��尡 �̹� ó���� ���� �ִٸ� ����
		if (dist[cur] < distance) continue;
		// ���� ���� ����� �ٸ� ������ ������ Ȯ��
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextDistance = distance + graph[cur][i].second;
			// ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ��� �������ش�.
			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	// ��� ���� ���� �Է�
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a -> b ���� ����� c��� �ϸ�
		graph[a].push_back({ b,c });
	}

	// �ִ� �Ÿ� ���̺� �������� �ʱ�ȭ
	fill(dist, dist + 100001, INF);

	dijkstra(start);

	// ��� ���� ���� ���� �ִ� �Ÿ��� ���
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}

	return 0;
}
