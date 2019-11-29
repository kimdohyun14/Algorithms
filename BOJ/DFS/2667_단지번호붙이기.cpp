#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[26][26];          // ��
bool visited[26][26];   // �湮�迭
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n;

vector<int> ans;
int cnt;  // dfs�� �� �� ����Ŭ�� �� ī��Ʈ

void dfs(int x, int y)
{
	cnt++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		// ��� üũ
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (visited[nx][ny] == false && a[nx][ny] == 1)
			{
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	/* Ž�� */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 && visited[i][j] == false)
			{
				dfs(i, j);
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(ans.begin(), ans.end()); // ���� ���� ������ ������������ ����

	/* ��� */
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}