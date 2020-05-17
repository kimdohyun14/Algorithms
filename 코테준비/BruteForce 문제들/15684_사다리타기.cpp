// https://yabmoons.tistory.com/47

// ���μ��� ��� ��������� ����̿��µ�, 2�������� ǥ���ϴ� ���..
// �ٽ� Ǯ���.
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, ans;
int a[11][30];
bool visit[11][30];

bool ladder_game()
{
	for (int i = 1; i <= N; i++) // ���μ�
	{
		int cur_num = i;
		for (int j = 1; j <= H; j++) // ���μ� ���� ��ġ
		{
			// �ش� cur_num(���μ�)���� 
			if (visit[cur_num][j] == true) cur_num = cur_num + 1;
			else if (visit[cur_num - 1][j] == true) cur_num = cur_num - 1;
		}

		if (cur_num != i) return false;
	}
	return true;
}

// ���μ� �ΰ���, ���� ��������
void select_line(int idx, int cnt)
{
	if (cnt >= 4) return;
	if (ladder_game()) // ���ӿ� �����Ѵٸ�, �� ���� ���μ��� ���� ���Ž�Ų��.
	{
		cout << cnt << endl;
		for (int i = 1; i <= N; i++) // ���μ�
		{
			for (int j = 1; j <= H; j++) // ���μ� ���� ��ġ
			{
				cout << visit[i][j] << ' ';
			}
			cout << endl;
		}

		cout << endl;
		ans = min(ans, cnt);
		return;
	}

	for (int i = idx; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (visit[j][i] == true) continue;
			if (visit[j - 1][i] == true) continue;
			if (visit[j + 1][i] == true) continue;

			visit[j][i] = true;
			select_line(i, cnt + 1);
			visit[j][i] = false;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ans = 987654321;
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		visit[b][a] = true; // b�� ���μ��� b+1 ���μ��� a�� ���μ����� �̾����.
	}

	select_line(1, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}