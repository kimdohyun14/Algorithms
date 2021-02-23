#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int baby = 2;
int eat = 0;

pair<int, int> shark;

int field[21][21];
bool check[21][21];
int dist[21][21];

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

vector<tuple<int, int, int>> v;

int solve(int x, int y)
{
	int ans = 0;
	while (true)
	{
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		v = vector<tuple<int, int, int>>();

		queue<pair<int, int>> q;
		q.push({ x, y });
		check[x][y] = true;
		dist[x][y] = 0;
		int cost = 0;
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny] == false && baby >= field[nx][ny])
				{
					q.push({ nx,ny });
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;

					// ��Ƹ��� �� �ִ� ������� �������� �� �ִ´�.
					if (baby > field[nx][ny] && field[nx][ny] != 0)
						v.push_back({ dist[nx][ny], nx, ny });
				}
			}
		}

		if (!v.empty()) // ��� ���� �� �ִ� ����Ⱑ �����Ѵٸ�
		{
			sort(v.begin(), v.end()); // (�Ÿ�, ���� ��, ���� ����) ������ ������.

			tie(cost, x, y) = v.front(); // ���� �켱������ ���� ����� �� ������ �Դ´�.
			field[x][y] = 0;
			eat++;
			if (eat == baby) // �ڽ��� ũ��� ���� ���� ����⸦ �� ũ�⸸ŭ �Ծ��ٸ�, �Ʊ� ����� ũ�⸦ �÷��ش�
			{
				eat = 0;
				baby++;
			}
			ans += dist[x][y]; // �� ����⸦ �Դµ� ���� �ɸ� �ð��� �����ش�.
		}
		else
			break;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 9)
			{
				shark = { i,j };
				field[i][j] = 0;
			}
		}
	}

	cout << solve(shark.first, shark.second) << '\n';
	return 0;
}