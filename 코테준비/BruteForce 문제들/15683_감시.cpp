// https://yabmoons.tistory.com/46
// ������ �ݹ� ���؉�����, CCTV�� ��� ��츦 ����ϴ� �κ��� ������ ��ٷο���.
// ���߿� �ٽ� Ǯ���.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans;
int a[9][9];   // ��
int c_a[9][9]; // ���� ��

vector<pair<pair<int,int>, pair<int,int>>> v; // CCTV [(x,y),(��ȣ,����)]

void copy_Map()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			c_a[i][j] = a[i][j];
		}
	}
}

void right(int x, int y)
{
	for (int i = y + 1; i < M; i++)
	{
		if (c_a[x][i] == 6) break;
		if (c_a[x][i] >= 1 && c_a[x][i] <= 5) continue;

		c_a[x][i] = -1;
	}
}

void left(int x, int y)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (c_a[x][i] == 6) break;
		if (c_a[x][i] >= 1 && c_a[x][i] <= 5) continue;

		c_a[x][i] = -1;
	}
}

void down(int x, int y)
{
	for (int i = x + 1; i < N; i++)
	{
		if (c_a[i][y] == 6) break;
		if (c_a[i][y] >= 1 && c_a[i][y] <= 5) continue;

		c_a[i][y] = -1;
	}
}

void up(int x, int y)
{
	for (int i = x - 1; i >= 0; i--)
	{
		if (c_a[i][y] == 6) break;
		if (c_a[i][y] >= 1 && c_a[i][y] <= 5) continue;

		c_a[i][y] = -1;
	}
}

void check_cctv_area()
{
	copy_Map();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second.first == 1)
		{
			if (v[i].second.second == 0) right(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 1) left(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 2) down(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 3) up(v[i].first.first, v[i].first.second);
		}
		else if (v[i].second.first == 2)
		{
			if (v[i].second.second == 0 || v[i].second.second == 1)
			{
				right(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2 || v[i].second.second == 3)
			{
				up(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 3)
		{
			if (v[i].second.second == 0)
			{
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2)
			{
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3)
			{
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 4)
		{
			if (v[i].second.second == 0)
			{
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2)
			{
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3)
			{
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 5)
		{
			right(v[i].first.first, v[i].first.second);
			down(v[i].first.first, v[i].first.second);
			left(v[i].first.first, v[i].first.second);
			up(v[i].first.first, v[i].first.second);
		}
	}
}

int numOfSecretArea()
{
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (c_a[i][j] == 0) total++;
		}
	}
	return total;
}

// CCTV ������ �̸� ���س���, �� ���¿��� �簢���븦 ���ؼ� �����Ѵ�. (���)
void set_CCTV_Direction(int cnt)
{
	if (cnt == v.size())
	{
		// ������ ������ CCTV�� �˻��ϰ�,
		check_cctv_area();
		// �簢���븦 ���ؼ� �ּ� ũ�⸦ ���Ѵ�.
		ans = min(ans, numOfSecretArea());
		return;
	}

	v[cnt].second.second = 0;
	set_CCTV_Direction(cnt + 1);

	v[cnt].second.second = 1;
	set_CCTV_Direction(cnt + 1);

	v[cnt].second.second = 2;
	set_CCTV_Direction(cnt + 1);

	v[cnt].second.second = 3;
	set_CCTV_Direction(cnt + 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ans = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			if (a[i][j] >= 1 && a[i][j] <= 5)
				v.push_back({ {i,j},{a[i][j], -1} });
		}
	}

	set_CCTV_Direction(0);
	cout << ans;
	return 0;
}