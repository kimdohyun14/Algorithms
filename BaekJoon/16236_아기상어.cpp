/* https://yabmoons.tistory.com/160
�����ϰ�, �Ű澵�� ���� ������� ����ü�� �̿��ؼ� ����ϸ� ���ϴ�. */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct
{
	int x;
	int y;
	int size;
	int eat_num;
	int time;
}Shark;

typedef struct
{
	int x;
	int y;
	int dist;
}Food;

int N;
int stage[20][20];
bool visit[20][20];

Shark shark;
vector<Food> fish;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool Sorting_Standard(Food& a, Food& b)
{
	/* �Ÿ��� -> x��� -> y��� */
	if (a.dist <= b.dist)
	{
		if (a.dist == b.dist)
		{
			if (a.x <= b.x)
			{
				if (a.x == b.x)
				{
					if (a.y < b.y)
					{
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void BFS(int a, int b)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	visit[a][b] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (visit[nx][ny] == false)
				{
					/* �� �����̸�, �湮�� ������ �Ÿ� + 1 */
					if (stage[nx][ny] == 0)
					{
						visit[nx][ny] = true;
						q.push({ {nx,ny}, dist + 1 });
					}
					/* ���� �������, ����⸦ �־��ְ� �湮�� ������ �Ÿ� + 1 */
					else if (stage[nx][ny] < shark.size)
					{
						Food food;
						food.x = nx;
						food.y = ny;
						food.dist = dist + 1;
						
						fish.push_back(food);
						visit[nx][ny] = true;
						q.push({ {nx, ny}, dist + 1 });
					}
					/* ũ�Ⱑ ���� �������, �湮�� ������ �Ÿ� + 1 */
					else if (stage[nx][ny] == shark.size)
					{
						visit[nx][ny] = true;
						q.push({ {nx,ny}, dist + 1 });
					}
				}
			}
		}
	}
}

void Simulation()
{
	while (1)
	{
		fish.clear();
		memset(visit, false, sizeof(visit));

		/* �Ʊ� �� ����⸦ Ž���Ѵ�. */
		BFS(shark.x, shark.y);

		/* ���� �� �ִ� ����Ⱑ ���ٸ� */
		if (fish.size() == 0)
		{
			cout << shark.time;
			break;
		}
		/* ���� �� �ִ� ����Ⱑ 1���� */
		else if (fish.size() == 1)
		{
			stage[fish[0].x][fish[0].y] = 9;
			stage[shark.x][shark.y] = 0;
			shark.x = fish[0].x;
			shark.y = fish[0].y;
			shark.eat_num++;
			shark.time += fish[0].dist;

			if (shark.eat_num == shark.size)
			{
				shark.eat_num = 0;
				shark.size++;
			}
		}
		/* ���� �� �ִ� ����Ⱑ ���ٸ�, ���� ����� �������� ����. */
		else
		{
			sort(fish.begin(), fish.end(), Sorting_Standard);
			stage[fish[0].x][fish[0].y] = 9;
			stage[shark.x][shark.y] = 0;
			shark.x = fish[0].x;
			shark.y = fish[0].y;
			shark.eat_num++;
			shark.time += fish[0].dist;

			if (shark.eat_num == shark.size)
			{
				shark.eat_num = 0;
				shark.size++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> stage[i][j];
			if (stage[i][j] == 9)
			{
				// x, y, size, eat_num, time
				shark = { i,j,2,0,0 };
			}
		}
	}

	Simulation();
	return 0;
}