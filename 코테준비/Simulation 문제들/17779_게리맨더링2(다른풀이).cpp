#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int FIVE = 4;

int N, board[21][21], people[5], ans;
bool visited[21][21];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0 ,-1 ,0 };

void select_five_area(int x, int y, int d1, int d2)
{
	int i, j;
	memset(people, 0, sizeof(people));
	memset(visited, 0, sizeof(visited));

	// 2. 5�� ���ű� ��輱
	for (i = 0; i <= d1; ++i)
	{
		visited[x + i][y - i] = true;
		visited[x + d2 + i][y + d2 - i] = true;
		people[FIVE] += board[x + i][y - i] + board[x + d2 + i][y + d2 - i];
	}
	for (i = 1; i < d2; ++i)
	{
		visited[x + i][y + i] = true;
		visited[x + d1 + i][y - d1 + i] = true;
		people[FIVE] += board[x + i][y + i] + board[x + d1 + i][y - d1 + i];
	}

	// 3. 5�� ���ű� ���� Ž��
	for (i = 0; i < d1; ++i)
	{
		j = 0;
		while (!visited[x + i + j + 1][y - i])
		{
			visited[x + i + j + 1][y - i] = true;
			people[FIVE] += board[x + i + j + 1][y - i];
			++j;
		}
	}
	for (i = 1; i < d2; ++i)
	{
		j = 0;
		while (!visited[x + i + j + 1][y + i])
		{
			visited[x + i + j + 1][y + i] = true;
			people[FIVE] += board[x + i + j + 1][y + i];
			++j;
		}
	}
	// 4. 1 ~ 4 ���ű� ����
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			if (visited[i][j] == true) continue;
			if (i < x + d1 && j <= y)                people[0] += board[i][j];
			else if (i <= x + d2 && y < j)           people[1] += board[i][j];
			else if (x + d1 <= i && j < y - d1 + d2) people[2] += board[i][j];
			else if (x + d2 < i && y - d1 + d2 <= j) people[3] += board[i][j];
		}
	}

	// 5. ���� ���� �ִ� �α�, �ּ� �α��� ���̷� ����
	pair<int*, int*> p = minmax_element(people, people + 5);
	ans = min(ans, int(*p.second - *p.first));
}

void divide_area()
{
	int x, y, d1, d2;

	// 1. ������ ��ġ���� d1, d2�� �ÿ����� �õ�
	for (x = 1; x <= N - 2; ++x)
	{
		for (y = 2; y <= N - 1; ++y)
		{
			d1 = 1, d2 = 1;

			while (true)
			{
				if (x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N)
					select_five_area(x, y, d1, d2++);
				else
				{
					++d1, d2 = 1;
					if (!(x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N))
						break;
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	register int i, j;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			cin >> board[i][j];

	ans = 987654321;
	divide_area();
	cout << ans;
	return 0;
}