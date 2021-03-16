#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// ȭ�� Ž�� ����
int tc, n;
int graph[125][125], d[125][125];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
const int INF = 1e9;

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> tc;
	while (tc--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];

		// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
		fill(d[0], d[0] + 125 * 125, INF);

		int x = 0, y = 0;
		priority_queue<pair<int, pair<int, int> > > pq; // {(���), (��ǥ)}
		pq.push({ -graph[x][y], {0,0} });
		d[x][y] = graph[x][y];
		while (!pq.empty())
		{
			int distance = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (d[x][y] < distance) continue;
			// ���� ���� ����� �ٸ� ������ ������ Ȯ��
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				int nextDistance = distance + graph[nx][ny];
				if (nextDistance < d[nx][ny])
				{
					d[nx][ny] = nextDistance;
					pq.push({ -nextDistance, {nx,ny} });
				}
			}
		}

		cout << d[n - 1][n - 1] << '\n';
	}
}