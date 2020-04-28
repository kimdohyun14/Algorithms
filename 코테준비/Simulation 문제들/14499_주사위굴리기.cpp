#include <iostream>
#include <queue>
using namespace std;

int dice[4][3]; // �ֻ���
int a[21][21];  // ����
int N, M, K;
pair<int, int> now; // �ֻ����� ������ġ
pair<int, int> direction[4] = { {0,1}, {0,-1}, {-1,0}, {1,0} }; // ��, ��, ��, ��


int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> now.first >> now.second >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	queue<int> q;
	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;
		q.push(command);
	}

	// ��ɾ ���� ������ ������ �����Ѵ�.
	while (!q.empty())
	{
		int dir = q.front();
		q.pop();

		int cx = now.first;
		int cy = now.second;

		
		if (dir == 1) // ����
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				// �ֻ����� ��ġ�� ����
				now = { nx,ny };

				// �ֻ��� ����
				int temp = dice[3][1];
				dice[3][1] = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = temp;

				// �̵��� ĭ�� 0�̸� �ֻ����� �ٴڸ鿡 ���� ���ڰ� ������ ����
				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				// 0�� �ƴ� ��쿡�� ������ ������ ���� �ֻ����� �ٴ� �鿡 ����
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}
				
				// �ֻ����� ���� ������ ����Ѵ�.
				cout << dice[3][1] << '\n';
			}
		}
		else if (dir == 2) // ����
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				now = { nx,ny };
				int temp = dice[3][1];
				dice[3][1] = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = dice[1][0];
				dice[1][0] = temp;

				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}

				cout << dice[3][1] << '\n';
			}
		}
		else if (dir == 3) // ����
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				now = { nx,ny };
				int temp = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = temp;

				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}

				cout << dice[3][1] << '\n';
			}
		}
		else if (dir == 4) // ����
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				now = { nx,ny };
				int temp = dice[3][1];
				dice[3][1] = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = temp;

				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}

				cout << dice[3][1] << '\n';
			}
		}
	}


	return 0;
}