// https://yabmoons.tistory.com/41
// �ϳ��ϳ� ������ ������ ������, ������ �� �ִ� �κ��� ������ �ؼ� ������ ����ȭ ��Ű�� �͵� �߿��ϴ�.
// ������ �ٽ� Ǯ���.
#include <iostream>

#define MAX 50
using namespace std;

int N, M;
int a[MAX][MAX];
bool visit[MAX][MAX];

struct Robot
{
	int x, y, d;
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int turn_Direction(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else if (d == 3) return 2;
}

void simulation(Robot robot)
{
	int x = robot.x;
	int y = robot.y;
	int d = robot.d;
	int room = 0;
	a[x][y] = 2;
	room++;

	int nx, ny, nd;
	while (1)
	{
		int temp_d = d;
		bool can_clean = false;
		int can_not_clean = 0;

		// ���ʹ������κ��� 4���� ���ʴ�� Ž��
		for (int i = 0; i < 4; i++)
		{
			nd = turn_Direction(d);
			nx = x + dx[nd];
			ny = y + dy[nd];

			// û�Ҹ� �� �� �ִٸ�? û������.
			if (a[nx][ny] == 0)
			{
				can_clean = true;
				break;
			}

			// ���̰ų�, û�Ҹ� �߰ų�, ������ ��� ���
			else if (a[nx][ny] == 1 || a[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= M))
			{
				d = nd;
				can_not_clean++;
			}
		}
		
		// û���ϱ�.
		if (can_clean == true)
		{
			a[nx][ny] = 2;
			room++;
			d = nd;
		}

		if (can_not_clean == 4)
		{
			// �����Ѵ�.
			nx = x - dx[temp_d];
			ny = y - dy[temp_d];
			d = temp_d;
			// ���� ���̰ų�, ���� ��� �۵� ����.
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || a[nx][ny] == 1) break;
		}

		x = nx;
		y = ny;
	}

	cout << room << endl;
}

int main()
{
	Robot robot;
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	cin >> robot.x >> robot.y >> robot.d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	simulation(robot);
	return 0;
}