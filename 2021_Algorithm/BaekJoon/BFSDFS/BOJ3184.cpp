#include <iostream>
#include <queue>
using namespace std;

// �����ȿ��� ���� ���뺸�� ������ ���� �̱��, �ƴϸ� ���밡 �̱��.
// �������� ���ϴ� ���� ���� ��� �����̴�.

int r, c;
char field[251][251];
bool vis[251][251];
int sheep, wolf;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	int sheep_count = 0, wolf_count = 0;

	if (field[x][y] == 'o') 
		sheep_count++;
	else if (field[x][y] == 'v') 
		wolf_count++;

	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (field[nx][ny] == 'o' && !vis[nx][ny])
			{
				sheep_count++;
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (field[nx][ny] == 'v' && !vis[nx][ny])
			{
				wolf_count++;
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if(field[nx][ny] == '.' && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	if (sheep_count > wolf_count) 
		sheep += sheep_count;
	else 
		wolf += wolf_count;
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> field[i][j];

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (field[i][j] != '#' && !vis[i][j])
			{
				bfs(i, j);
			}
		}
	}

	cout << sheep << ' ' << wolf << '\n';
	return 0;
}