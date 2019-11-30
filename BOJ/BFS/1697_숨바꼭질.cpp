#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dist[200001];
int n, k;

bool check(int pos)
{
	if (pos == k)
		return true;
	else
		return false;
}

// �Ÿ� ���� �ð��� �����ؼ� �迭�� �����Ѵ�.
void bfs(int n, int k)
{
	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		// n - 1
		if (cur - 1 >= 0 && cur - 1 <= 100000)
		{
			if (dist[cur - 1] == -1)
			{
				dist[cur - 1] = dist[cur] + 1; // 1�� ����
				q.push(cur - 1);
			}

			if (check(cur - 1)) // ���� ã������ �� �̻� ã�� �ʰ� Ż��
				return;
		}

		// n + 1
		if (cur + 1 >= 0 && cur + 1 <= 100000)
		{
			if (dist[cur + 1] == -1)
			{
				dist[cur + 1] = dist[cur] + 1;
				q.push(cur + 1);
			}

			if (check(cur - 1))
				return;
		}

		// 2 * n
		if (cur * 2 >= 0 && cur * 2 <= 100000)
		{
			if (dist[cur * 2] == -1)
			{
				dist[cur * 2] = dist[cur] + 1;
				q.push(cur * 2);
			}

			if (check(cur - 1))
				return;
		}
	}
}

int main()
{
	/* �Է� */
	cin >> n >> k;
	memset(dist, -1, sizeof(dist)); // �湮�� ���������� -1�� ǥ��

	/* Ž�� */
	bfs(n, k);

	/* ��� */
	cout << dist[k];
	return 0;
}
