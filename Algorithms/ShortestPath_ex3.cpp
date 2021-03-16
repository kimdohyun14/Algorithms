#include <iostream>
#include <algorithm>
using namespace std;

// ��Ȯ�� ���� ����
const int INF = 1e9;

int N, M;
int graph[501][501];

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	fill(graph[0], graph[0] + 501 * 501, INF);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i == j) graph[i][j] = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int ans = 0;
	// �� �л��� ��ȣ�� ���� �� �� Ȯ���ϸ� ���� �������� üũ
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] != INF || graph[j][i] != INF)
				cnt++;
		}

		if (cnt == N)
			ans++;
	}

	cout << ans << '\n';
	return 0;
}