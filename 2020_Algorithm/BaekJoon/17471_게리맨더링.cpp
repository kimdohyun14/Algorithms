#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int person[11];                // �� ������ �α���
vector<vector<int>> graph;     // ����� ���� �׷���

bool sel[11];                  // ���� ����
bool visited[11];              // �湮 ����

vector<int> v1, v2;            // ���� v1, v2
int v1_cnt, v2_cnt, city_cnt;
int ans = 987654321;

void init_select()
{
	for (int i = 1; i <= N; i++)
	{
		sel[i] = false;
	}
}

void init_visit()
{
	for (int i = 1; i <= N; i++)
	{
		visited[i] = false;
	}
}

// ������ ���� ����Ǿ��ִ��� �׷����� Ž���Ѵ�.
void dfs(int x)
{
	city_cnt++;
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int next = graph[x][i];
		if (visited[next] == false)
		{
			dfs(next);
		}
	}
}

void select_city(int idx, int cnt, int goal)
{
	if (cnt == goal)
	{
		v1.clear();
		v2.clear();
		// ������ v1�� v2�� ������.
		for (int i = 1; i <= N; i++)
		{
			if (sel[i] == true) v1.push_back(i);
			else v2.push_back(i);
		}

		// v1 ����
		city_cnt = 0;
		init_visit();
		for (int i = 0; i < v2.size(); i++) visited[v2[i]] = true;
		dfs(v1.front());
		if (v1.size() != city_cnt) return; // �ش� v1 ������ ���� ����Ǿ� �ִ���? �ƴ϶�� ����.

		// v2 ����
		city_cnt = 0;
		init_visit();
		for (int i = 0; i < v1.size(); i++) visited[v1[i]] = true;
		dfs(v2.front());
		if (v2.size() != city_cnt) return;

		// �� ���ű��� �α� ���̸� ���ؼ� ���Ž�Ų��.
		int v1_total = 0, v2_total = 0;
		for (int i = 0; i < v1.size(); i++) v1_total += person[v1[i]];
		for (int i = 0; i < v2.size(); i++) v2_total += person[v2[i]];

		ans = min(ans, abs(v1_total - v2_total));
		return;
	}

	// ���� ���ϱ�
	for (int i = idx; i <= N; i++)
	{
		if (sel[i] == true) continue;
		sel[i] = true;
		select_city(i, cnt + 1, goal);
		sel[i] = false;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	graph.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> person[i];
	for (int i = 1; i <= N; i++)
	{
		int len;
		cin >> len;
		for (int j = 0; j < len; j++)
		{
			int u;
			cin >> u;
			// �瓇�� ����
			graph[i].push_back(u);
			graph[u].push_back(i);
		}
	}

	// ������ [i] , [N - i] �� �������� ������ Ȯ���Ѵ�.
	for (int i = 1; i < N; i++)
	{
		init_select();
		select_city(1, 0, i);
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;

	return 0;
}