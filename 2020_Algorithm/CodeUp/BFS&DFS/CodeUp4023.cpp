#include <iostream>
#include <vector>
using namespace std;

int a[19][19];

int dx[] = { 0,1,1,-1 };
int dy[] = { 1,0,1,1 };
bool isWin;
int win, r, c;

void dfs(int x, int y, int cnt, int color, int d)
{
	if (x == -1 || y == -1 || x == 19 || y == 19) return;

	// ���� ����, �������� �ݴ� ������ ���� �ٸ��ٸ�
	if ((cnt == 5) && (a[x + dx[d]][y + dy[d]] != color) && (a[x - dx[d] * 5][y - dy[d] * 5] != color))
	{
		isWin = true;
		win = color;
		r = x - dx[d] * 4 + 1; // 1�� ���� ������ �ε����� 0�� �������� ��ұ� ����
		c = y - dy[d] * 4 + 1;
		return;
	}

	// ���� ���⵵ �̾����ٸ� ȣ��
	if ((cnt >= 2) && a[x + dx[d]][y + dy[d]] == color)
		dfs(x + dx[d], y + dy[d], cnt + 1, color, d);

	// ó���̶�� 4���� Ž��
	if (cnt == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (a[x + dx[i]][y + dy[i]] == color)
			{
				dfs(x + dx[i], y + dy[i], cnt + 1, color, i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (isWin) break;
		for (int j = 0; j < 19; j++)
		{
			if (a[i][j] != 0)
				dfs(i, j, 1, a[i][j], 0);
		}
	}

	if (isWin) cout << win << '\n' << r << ' ' << c << '\n';
	else cout << 0;
	return 0;
}