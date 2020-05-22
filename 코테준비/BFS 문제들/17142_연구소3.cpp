#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 51
using namespace std;

int N, M, safe_zone, copy_zone, ans = 987654321;
int stage[MAX][MAX];
int copy_stage[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> all_virus;
bool choice_virus[10];

// ���̷��� ��Ʈ����
void BFS(vector<pair<int, int>>& v)
{
	int time = 0;

	// ���ʿ� ���� ������ 0�� ���� �������� �ʾƵ� �ȴ�.
	if (copy_zone == 0)
	{
		ans = 0;
		return;
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) q.push({ v[i].first, v[i].second });

	while (!q.empty())
	{
		time++; // 1�� ����

		int cycle = q.size();
		for (int i = 0; i < cycle; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N)
				{
					
					if (visit[nx][ny] == true) continue;

					if (copy_stage[nx][ny] == 0 || copy_stage[nx][ny] == 2)
					{
						//cout << "[" << nx << "," << ny << "]" << endl;
						if (copy_stage[nx][ny] == 0) copy_zone--;

						visit[nx][ny] = true;
						copy_stage[nx][ny] = 4;
						q.push({ nx,ny });
					}
				}
			}
		}

		// ���̷����� ���Ľ��״µ�, ���� ������ �ϳ��� ���ٸ�
		if (copy_zone == 0)
		{
			ans = min(ans, time);
			return;
		}
	}
}

void CopyMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copy_stage[i][j] = stage[i][j];
		}
	}
}

void Initialize()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
		}
	}
}


// ���̷��� M�� �̱�
void Select_Virus(int index, int cnt)
{
	if (cnt == M)
	{
		CopyMap();    // �� ����
		Initialize(); // �湮�迭 �ʱ�ȭ 
		copy_zone = safe_zone; // ������ ���� �ʱ�ȭ
		vector<pair<int, int>> virus; // Ȱ�� ���̷��� ��ġ
		for (int i = 0; i < 10; i++)
		{
			if (choice_virus[i] == true)
			{
				virus.push_back({ all_virus[i].first , all_virus[i].second });
				copy_stage[all_virus[i].first][all_virus[i].second] = 5;
				visit[all_virus[i].first][all_virus[i].second] = true;
			}
		}

		// ���̷��� ����
		BFS(virus);
	}

	for (int i = index; i < all_virus.size(); i++)
	{
		if (choice_virus[i] == true) continue;
		choice_virus[i] = true;
		Select_Virus(i, cnt + 1);
		choice_virus[i] = false;
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> stage[i][j];
			if (stage[i][j] == 2) all_virus.push_back({ i,j });
			else if (stage[i][j] == 0) safe_zone++;
		}
	}

	Select_Virus(0, 0);
	if (ans == 987654321) cout << -1;
	else cout << ans;
	return 0;
}