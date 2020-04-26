#include <iostream>
#include <algorithm>

#define MAX_SIZE 50 + 1
using namespace std;

char a[MAX_SIZE][MAX_SIZE];
char copy_a[8][8];
char copy_b[8][8];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// (i,j)�� �������� 8 * 8 ũ�⸦ ���� �� �ִٸ�
			if (i + 7 < n && j + 7 < m)
			{
				int x = 0, y = 0;
				// copy�ʿ� �����س���
				for (int k = i; k <= i + 7; k++, x++)
				{
					for (int l = j; l <= j + 7; l++, y++)
					{
						copy_a[x][y] = a[k][l];
						copy_b[x][y] = a[k][l];
					}
					y = 0;
				}

				int cnt = 0;
				// 8 * 8 ü���ǿ� �ʿ��� �κ��� ��ĥ�Ѵ�.
				// ���� ���� ���� ����� ��� copy_a
				if (copy_a[0][0] == 'B')
				{
					copy_a[0][0] = 'W';
					cnt++;
				}
				for (int i2 = 0; i2 < 8; i2++)
				{
					for (int j2 = 0; j2 < 8; j2++)
					{
						int cx = i2;
						int cy = j2;
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cx + dx[dir];
							int ny = cy + dy[dir];
							if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
							{
								// ���� �����ϴ� �� ���� �簢���� �ٸ� ������ ĥ������ �ϹǷ�
								if (copy_a[nx][ny] == copy_a[cx][cy])
								{
									cnt++;
									if (copy_a[cx][cy] == 'B') copy_a[nx][ny] = 'W';
									else copy_a[nx][ny] = 'B';
								}
							}
						}
					}
				}
				if (ans == -1) ans = cnt;
				else ans = min(ans, cnt);

				// ���� ���� ���� �������� ��� copy_b
				cnt = 0;
				if (copy_b[0][0] == 'W')
				{
					copy_b[0][0] = 'B';
					cnt++;
				}

				for (int i2 = 0; i2 < 8; i2++)
				{
					for (int j2 = 0; j2 < 8; j2++)
					{
						int cx = i2;
						int cy = j2;
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cx + dx[dir];
							int ny = cy + dy[dir];
							if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
							{
								// ���� �����ϴ� �� ���� �簢���� �ٸ� ������ ĥ������ �ϹǷ�
								if (copy_b[nx][ny] == copy_b[cx][cy])
								{
									cnt++;
									if (copy_b[cx][cy] == 'B') copy_b[nx][ny] = 'W';
									else copy_b[nx][ny] = 'B';
								}
							}
						}
					}
				}

				if (ans == -1) ans = cnt;
				else ans = min(ans, cnt);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}