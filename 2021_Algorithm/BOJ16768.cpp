#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���� ���ٹ�
// ���� ��ü�� �߸� ������ -> ������ ���� �������� ������ �� �˾Ҵµ�
// �װ� �ƴ϶� ������ �ֵ��� k�̻��̸� ���� �� ����.
// �ð� �ʰ��� ���� �ذ���� ���� �ۼ���.

char mp[100][11];
char visit[100][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;

int removeBlock(int n, int k); // ��ϵ��� �����Ѵ�
void bfs(int x, int y, int n); // ������ ����� ã�Ƽ� ��ŷ
void moveBlock(int n);         // �߷� �̵�
void print(int n);             // ���

int main()
{
	freopen("input.txt", "r", stdin);

	int n, k;
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++) // ���ڿ��� �޴� ����� ���.
		scanf("%s\n", mp[i]);

	// �ð� ���⵵ 1000 * 1000 = 1,000,000
	while (removeBlock(n, k)) // �۾��� �ߴٸ�
	{
		moveBlock(n); // �߷����� ��ϵ��� ����Ʈ����.
	}

	print(n);
	return 0;
}

int removeBlock(int n, int k)
{
	int ret = 0;
	fill(visit[0], visit[0] + 100 * 11, false);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mp[i][j] == '0' || visit[i][j]) continue;

			bfs(i, j, n); // (i,j)�� �������� ������ �ֵ��� ã�´�.

			if ((int)v.size() < k) continue; // k�� �̻��̸�

			for (int a = 0; a < v.size(); a++) // �ش� ��ϵ��� ��Ʈ����.
			{
				int x = v[a].first;
				int y = v[a].second;
				mp[x][y] = '0';
				ret++;
			}
		}
	}

	return ret;
}

void bfs(int x, int y, int n)
{
	v.clear();
	char color = mp[x][y];
	visit[x][y] = true;
	q.push({ x,y });

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		v.push_back({ cx,cy });
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= 10 || visit[nx][ny]) continue;
			if (mp[nx][ny] != color) continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

void moveBlock(int n)
{
	for (int i = 0; i < 10; i++)
	{
		int po = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (mp[j][i] != '0')
				mp[po--][i] = mp[j][i];
		}

		for (int j = po; j >= 0; j--)
			mp[j][i] = '0';
	}
}

void print(int n)
{
	for (int i = 0; i < n; i++)
		printf("%s\n", mp[i]);
}
