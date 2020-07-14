// https://yabmoons.tistory.com/214

// 1�� ��ǥ�������� range�� �����ؼ� ��� ����� ���� �� Ȯ���غ��� �Ѵ�.
// ���߿� �ٽ�Ǯ��..
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10
using namespace std;

int ans = 987654321, total_cnt; // total_cnt : 1�� ����
int a[MAX][MAX];
bool visit[MAX][MAX];
bool already_ans = true;

vector<pair<int, int>> v;       // �����̸� ���� ��ǥ

// r * r �����̸� ����� �� �ִ���?
bool can_Fill(int x, int y, int r)
{
	int cnt = 0;
	for (int i = x; i < x + r; i++)
	{
		if (i >= MAX) break;
		for (int j = y; j < y + r; j++)
		{
			if (j >= MAX) break;
			if (a[i][j] == 1 && visit[i][j] == false) cnt++;
		}
	}

	if (cnt == r * r) return true;
	else return false;
}

// ��ŭ �����̷� ���� �� �ִ��� ������ ���Ѵ�.
int find_Range(int x, int y)
{
	if (can_Fill(x, y, 2) == true)
	{
		if (can_Fill(x, y, 3) == true)
		{
			if (can_Fill(x, y, 4) == true)
			{
				if (can_Fill(x, y, 5) == true)
				{
					return 5;
				}
				return 4;
			}
			return 3;
		}
		return 2;
    }
	return 1;
}

void make_Visit(int x, int y, int r, bool t)
{
	for (int i = x; i < x + r; i++)
	{
		for (int j = y; j < y + r; j++)
		{
			visit[i][j] = t;
		}
	}
}

// total : ������� ä�� Ƚ��
void dfs(int idx, int one, int two, int three, int four, int five, int total)
{
	int use = one + two + three + four + five;

	if (ans < use) return; // ���� ����� �������� ������ ������ ���亸�� ���ٸ� ����
	if (total == total_cnt)// ��� ĭ�� �� ĥ�� ���
	{
		ans = min(ans, use);
		return;
	}

	// �̹� �� ��ǥ�� �����̰� ĥ�����ִٸ�?
	if (visit[v[idx].first][v[idx].second] == true)
	{
		dfs(idx + 1, one, two, three, four, five, total);
		return;
	}

	// ���� ���������� ä�� �� �ִ� �������� �ִ� ũ�⸦ ���Ѵ�.
	int can_fill = find_Range(v[idx].first, v[idx].second);
	if (can_fill == 1)
	{
		if (one + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 1, true);
			dfs(idx + 1, one + 1, two, three, four, five, total + 1);
			make_Visit(v[idx].first, v[idx].second, 1, false);
		}
	}
	else if (can_fill == 2)
	{
		if (two + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 2, true);
			dfs(idx + 1, one, two + 1, three, four, five, total + 4);
			make_Visit(v[idx].first, v[idx].second, 2, false);
		}

		if (one + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 1, true);
			dfs(idx + 1, one + 1, two, three, four, five, total + 1);
			make_Visit(v[idx].first, v[idx].second, 1, false);
		}
	}
	else if (can_fill == 3)
	{
		if (three + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 3, true);
			dfs(idx + 1, one, two, three + 1, four, five, total + 9);
			make_Visit(v[idx].first, v[idx].second, 3, false);
		}

		if (two + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 2, true);
			dfs(idx + 1, one, two + 1, three, four, five, total + 4);
			make_Visit(v[idx].first, v[idx].second, 2, false);
		}

		if (one + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 1, true);
			dfs(idx + 1, one + 1, two, three, four, five, total + 1);
			make_Visit(v[idx].first, v[idx].second, 1, false);
		}
	}
	else if (can_fill == 4)
	{
		if (four + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 4, true);
			dfs(idx + 1, one, two, three, four + 1, five, total + 16);
			make_Visit(v[idx].first, v[idx].second, 4, false);
		}

		if (three + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 3, true);
			dfs(idx + 1, one, two, three + 1, four, five, total + 9);
			make_Visit(v[idx].first, v[idx].second, 3, false);
		}

		if (two + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 2, true);
			dfs(idx + 1, one, two + 1, three, four, five, total + 4);
			make_Visit(v[idx].first, v[idx].second, 2, false);
		}

		if (one + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 1, true);
			dfs(idx + 1, one + 1, two, three, four, five, total + 1);
			make_Visit(v[idx].first, v[idx].second, 1, false);
		}
	}
	else if (can_fill == 5)
	{
		if (five + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 5, true);
			dfs(idx + 1, one, two, three, four, five + 1, total + 25);
			make_Visit(v[idx].first, v[idx].second, 5, false);
		}

		if (four + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 4, true);
			dfs(idx + 1, one, two, three, four + 1, five, total + 16);
			make_Visit(v[idx].first, v[idx].second, 4, false);
		}

		if (three + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 3, true);
			dfs(idx + 1, one, two, three + 1, four, five, total + 9);
			make_Visit(v[idx].first, v[idx].second, 3, false);
		}

		if (two + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 2, true);
			dfs(idx + 1, one, two + 1, three, four, five, total + 4);
			make_Visit(v[idx].first, v[idx].second, 2, false);
		}

		if (one + 1 <= 5)
		{
			make_Visit(v[idx].first, v[idx].second, 1, true);
			dfs(idx + 1, one + 1, two, three, four, five, total + 1);
			make_Visit(v[idx].first, v[idx].second, 1, false);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				v.push_back({ i,j });
				total_cnt++;
				already_ans = false;
			}
		}
	}

	if (already_ans == true)
	{
		cout << 0;
		return 0;
	}

	dfs(0, 0, 0, 0, 0, 0, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}