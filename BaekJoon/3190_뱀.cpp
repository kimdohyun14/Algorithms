#include <iostream>
#include <deque>
using namespace std;

int N, K, L, X, ans;
int stage[101][101];

deque<pair<int, char>> dq;

// ��, ��, ��, ��
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int ChangeDirection(int d, char ch)
{
	if (d == 0)
	{
		if (ch == 'L') return 3;
		else return 2;
	}
	else if (d == 1)
	{
		if (ch == 'L') return 2;
		else return 3;
	}
	else if (d == 2)
	{
		if (ch == 'L') return 0;
		else return 1;
	}
	else if (d == 3)
	{
		if (ch == 'L') return 1;
		else return 0;
	}
}

int Simulation()
{
	int x = 1, y = 1, time = 0, dir = 0;
	deque<pair<int, int>> snake_pos; // ���� ǥ��

	// ���� ����
	stage[x][y] = 1; 
	snake_pos.push_back({ x,y });

	while (1)
	{
		time++;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || nx > N)   return time;
		if (ny < 1 || ny > N)   return time;
		if (stage[nx][ny] == 1) return time;

		if (stage[nx][ny] == -1)
		{
			stage[nx][ny] = 1;
			snake_pos.push_back({ nx,ny });
		}
		
		else
		{
			stage[nx][ny] = 1;
			snake_pos.push_back({ nx,ny });
			// ����� ���ٸ�, ���� �Ӹ��� ���� ������ �ٿ����Ѵ�. -> �߶���Ѵ�.
			int p1 = snake_pos.front().first;
			int p2 = snake_pos.front().second;
			snake_pos.pop_front();
			stage[p1][p2] = 0;
		}

		if(!dq.empty() && dq.front().first == time)
		{
			dir = ChangeDirection(dir, dq.front().second);
			dq.pop_front();
		}

		x = nx;
		y = ny;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		stage[r][c] = -1;
	}

	cin >> L;
	dq.resize(L);
	for (int i = 0; i < L; i++)
	{
		int num;
		char ch;
		cin >> num >> ch;
		dq[i] = { num, ch };
	}

	int ans = Simulation();
	cout << ans;
	return 0;
}