#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 20 + 1
using namespace std;

int N, answer = 987654321;
int stage[MAX][MAX];
int visit[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void ColoringFive(int x1, int y1, int x2, int y2, bool chk1, bool chk2)
{
	if (chk1 && chk2) // x, y �Ѵ� 1�� ����
	{
		for (int i = x1; i <= x2; i++, y1++)
		{
			visit[i][y1] = 5;
		}
	}
	else if (chk1) // x�� 1�� ����
	{
		for (int i = x1; i <= x2; i++, y1--)
		{
			visit[i][y1] = 5;
		}
	}
}

// 5�� ��輱 ���ʿ� 5�� �� ��ĥ���ش�.
void DFS(int x, int y, int color)
{
	visit[x][y] = color;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
		{
			if (visit[nx][ny] == 0)
			{
				DFS(nx, ny, color);
			}
		}
	}
}

// �����¿�� 5�� ��ĥ�Ǿ� �ִ� ���� 3����� �� �������� 5�� ��ĥ�ϰ� DFS Ž���Ѵ�.
void FindBoundary()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
				{
					if (visit[nx][ny] == 5) cnt++;
				}
			}

			if (cnt >= 3)
			{
				DFS(i, j, 5);
			}
		}
	}
}

// �� �������� �α� ���� ī��Ʈ�Ѵ�.
void Calculate()
{
	vector<int> total(5, 0);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 1) total[0] += stage[i][j];
			else if (visit[i][j] == 2) total[1] += stage[i][j];
			else if (visit[i][j] == 3) total[2] += stage[i][j];
			else if (visit[i][j] == 4) total[3] += stage[i][j];
			else if (visit[i][j] == 5) total[4] += stage[i][j];
		}
	}
	int max_value = *max_element(total.begin(), total.end());
	int min_value = *min_element(total.begin(), total.end());
	answer = min(answer, max_value - min_value);
}

void Section(int x, int y, int d1, int d2)
{
	// 5 ���� ��ĥ
	visit[x][y] = 5;
	ColoringFive(x + 1, y - 1, x + d1, y - d1, true, false);
	ColoringFive(x + 1, y + 1, x + d2, y + d2, true, true);
	ColoringFive(x + d1, y - d1, x + d1 + d2, y - d1 + d2, true, true);
	ColoringFive(x + d2, y + d2, x + d2 + d1, y + d2 - d1, true, false);
	FindBoundary();
	// 1 ���� ��ĥ
	for (int r = 1; r < x + d1; r++)
	{
		for (int c = 1; c <= y; c++)
		{
			if (visit[r][c] == 0) visit[r][c] = 1;
		}
	}
	// 2 ���� ��ĥ
	for (int r = 1; r <= x + d2; r++)
	{
		for (int c = y + 1; c <= N; c++)
		{
			if (visit[r][c] == 0) visit[r][c] = 2;
		}
	}
	// 3 ���� ��ĥ
	for (int r = x + d1; r <= N; r++)
	{
		for (int c = 1; c < y - d1 + d2; c++)
		{
			if (visit[r][c] == 0) visit[r][c] = 3;
		}
	}
	// 4 ���� ��ĥ
	for (int r = x + d2 + 1; r <= N; r++)
	{
		for (int c = y - d1 + d2; c <= N; c++)
		{
			if (visit[r][c] == 0) visit[r][c] = 4;
		}
	}
}

void Initialize()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visit[i][j] = 0;
		}
	}
}

void Selection()
{
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			for (int d1 = 0; d1 <= N; d1++)
			{
				for (int d2 = 0; d2 <= N; d2++)
				{
					if (x < x + d1 + d2 && x + d1 + d2 <= N)
					{
						if (y - d1 >= 1 && y - d1 < y && y < y + d2 && y + d2 <= N)
						{
							Initialize();           // �湮 �ʱ�ȭ
							Section(x, y, d1, d2);  // x, y, d1, d2�� ���ߴٸ� ������ 1, 2, 3, 4, 5�� ��������.
							Calculate();            // ����Ѵ�.
						}
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> stage[i][j];
		}
	}
	Selection();
	cout << answer;
	return 0;
}