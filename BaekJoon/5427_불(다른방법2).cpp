// ��ó : https://jaimemin.tistory.com/657
// ť�� 2�� �غ��ؼ� ������ ���鼭 BFS
// �� �����ϰ� �ڵ尡 �ۼ��ȴ�.
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

#define MAX_SIZE 1001
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int w, h;
char graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

pair<int, int > start;
vector<pair<int, int>> fire;

void show(int time)
{
	cout << time << "��" << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

}

int bfs()
{
	// �� queue
	queue<pair<int, int>> flame;
	for (int i = 0; i < fire.size(); i++)
		flame.push(fire[i]);

	// ��� queue
	queue<pair<int, int>> q;
	q.push(start);

	int time = 0;
	while (!q.empty())
	{
		// 1�� ��
		time++;

		// �� �̵�
		int fireSize = flame.size();
		for (int i = 0; i < fireSize; i++)
		{
			int cx = flame.front().first;
			int cy = flame.front().second;
			flame.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = cx + dx[j];
				int ny = cy + dy[j];

				if (nx >= 0 && ny >= 0 && nx < h && ny < w)
				{
					if (graph[nx][ny] == '.')
					{
						graph[nx][ny] = '*';
						flame.push({ nx,ny });
					}
				}
			}
		}

		// ��� �̵�
		int personSize = q.size();
		for (int i = 0; i < personSize; i++)
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			if (cx == 0 || cx == h - 1 || cy == 0 || cy == w - 1)
				return time;

			for (int j = 0; j < 4; j++)
			{
				int nx = cx + dx[j];
				int ny = cy + dy[j];

				if (nx >= 0 && ny >= 0 && nx < h && ny < w)
				{
					if (!visited[nx][ny] && graph[nx][ny] == '.')
					{
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		//show(time);
	}

	return -1; // Ż�� ����
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;

	while (tc--)
	{
		fire.clear();
		memset(visited, false, sizeof(visited));

		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> graph[i][j];
				if (graph[i][j] == '@')
					start = { i,j };
				if (graph[i][j] == '*')
					fire.push_back({ i,j });
			}
		}
		int ret = bfs();
		if (ret == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << ret << '\n';
	}

	return 0;
}