#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX_SIZE 1001
using namespace std;

int a[MAX_SIZE][MAX_SIZE];   // �丶�� ����, �湮����
int b[MAX_SIZE][MAX_SIZE];   // ���ϸ��� �;�����
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int N, M;
vector<pair<int, int>> start; // ��� ��ǥ

// ��� �丶�䰡 �� �;����� üũ
bool isFinish()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (a[i][j] == 0)
				return false;

	return true;
}

// �ּ� �ϼ� ���ϱ�
int operation()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (b[i][j] > ret)
				ret = b[i][j];
		}
	}

	return ret;
		
}

int bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < start.size(); i++)
	{
		int x = start[i].first, y = start[i].second;
		q.push({ x,y });
		b[x][y] = 0;
	}
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (a[nx][ny] == 0) // �������� �丶����
				{
					a[nx][ny] = 1;
					b[nx][ny] = b[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	
	if (isFinish())
		return operation();
	else
		return -1;
}

void input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1)
				start.push_back({ i,j });
		}
	}
}

void output(int ans)
{
	if (ans == -1)
		printf("-1\n");
	else
		printf("%d\n", ans);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	input();
	int ans = bfs();
	output(ans);
	return 0;
}