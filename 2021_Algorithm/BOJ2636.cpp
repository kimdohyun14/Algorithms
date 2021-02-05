#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 101;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int a[MAX][MAX]; // ���� ��
int b[MAX][MAX];

int r, c, time, finalSize;
queue<pair<int, int>> nextQ;

void show()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void divideAir() // �ܺ� ���� 1, ���� ���� 0���� ���н�Ű��
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	b[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (a[nx][ny] == 0 && b[nx][ny] == 0) // ġ� �ƴϸ鼭 ������ ���
			{
				b[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void findCheeseAir() // �ܺ� ���� �߿�����, ġ��� ������ ���� ã��
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == 1)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (a[nx][ny] == 1)
					{
						nextQ.push({ i,j });
						break;
					}
				}
			}
		}
	}
}

void meltCheese()
{
	// nextQ�� ������ �����ϰ� �����.
	// ġ� �ִ� ��ǥ�� ġ� �쿩�ְ�, �ش� ġ���� ��ǥ�� nextQ�� �־���.
	// ���� �κ��� ���� ġ� ���� �� �ִ� �ܺ� �����̱� ����
	queue<pair<int, int>> q = nextQ;
	while (!nextQ.empty()) nextQ.pop();
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (a[nx][ny] == 1)
			{
				a[nx][ny] = 0;
				nextQ.push({ nx,ny });
			}
		}
	}
}

void addAir()
{
	// �ܺΰ��� + ���ΰ���
	// nextQ���� ���� ġ��� ������ �ܺΰ����̹Ƿ�,
	// BFS�� Ž���ϴٰ� ���ΰ��⸦ ������ �� ���� �ܺΰ���� ���� �����̹Ƿ� �־��ش�.
	// ��, nextQ���� ������ �ܺΰ��⿡ �߰����� ���ΰ��Ⱑ �ܺΰ��Ⱑ �Ǵ� �κе� �־��ش�.
	queue<pair<int, int>> q = nextQ;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (b[nx][ny] == 0)
			{
				b[nx][ny] = 1;
				q.push({ nx,ny });
				nextQ.push({ nx,ny });
			}
		}
	}
}

bool isFinish()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 1) return false;
		}
	}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
				b[i][j] = -1;
		}
	}
	divideAir();
	findCheeseAir();
	while (1)
	{
		if (isFinish()) break; // ġ� �� ��Ҵ��� üũ
		meltCheese();
		finalSize = nextQ.size();
		addAir();
		time++;
	}

	cout << time << '\n' << finalSize << '\n';
	return 0;
}