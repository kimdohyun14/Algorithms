// https://mygumi.tistory.com/243
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int a[21][21];
bool visited[21];
int N, ans = 987654321;

int getStat(vector<int>& v)
{
	int result = 0;
	int len = N / 2;
	for (int i = 1; i <= len; i++)
	{
		for (int j = i + 1; j <= len; j++)
		{
			result += a[v[i]][v[j]];
			result += a[v[j]][v[i]];
		}
	}
	return result;
}

void divideTeam()
{
	vector<int> a(N / 2 + 1);
	vector<int> b(N / 2 + 1);
	int ai = 1, bi = 1;
	// ������ ��쿡���� �� ���� �迭�� ��Ÿ����.
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) a[ai++] = i;
		else b[bi++] = i;
	}

	// �� ���� �ɷ� ���̸� ���Ѵ�.
	int a_stat = getStat(a);
	int b_stat = getStat(b);
	int diff = abs(a_stat - b_stat);

	ans = min(ans, diff);
}

// �� ������ ������.
void dfs(int v, int len)
{
	if (len == N / 2)
	{
		divideTeam();
	}
	else
	{
		for (int i = v + 1; i <= N; i++)
		{
			if (visited[i] == true) continue;
			visited[i] = true;
			dfs(i, len + 1);
			visited[i] = false; // backtracking
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a[i][j];
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}