// https://yabmoons.tistory.com/161

// 2�ð� Ǯ�ٰ� �ᱹ ����, �ô�....
// vector<int> map[MAX][MAX]�� �ϸ� ���� Ǯ����.. ���߿� �ٽ� Ǯ��.
// �߰������� ���� ĭ�� ���� ���� ������ ���� ���� ������, ���� ��������.
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 11
using namespace std;

int N, M, K;
int energe[MAX][MAX];        // ���� ���
int insert_energe[MAX][MAX]; // �ܿ￡ �߰� �Ǵ� ���

vector<int> a[MAX][MAX];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1,  0,  1 ,-1,1,-1, 0, 1 };

void SpringAndSummer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (a[i][j].size() == 0) continue;

			int die_tree_energe = 0;
			vector<int> temp;

			// � �������� ����� �Ծ�� �ϹǷ� ������������ �����س���,
			sort(a[i][j].begin(), a[i][j].end());
			for (int k = 0; k < a[i][j].size(); k++)
			{
				int age = a[i][j][k];

				if (energe[i][j] >= age)
				{
					energe[i][j] -= age;
					temp.push_back(age + 1);
				}
				else
				{
					// ����� �����ϴٴ� �ǹ̴� �ᱹ �״´ٴ� �ǹ�
					// ���߿� ���� ���� ���� / 2 ��ŭ�� ����
					die_tree_energe += (age / 2);
				}
			}

			a[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
			{
				a[i][j].push_back(temp[k]);
			}
			energe[i][j] += die_tree_energe;
		}
	}
}

void Fall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (a[i][j].size() == 0) continue;

			for (int k = 0; k < a[i][j].size(); k++)
			{
				int age = a[i][j][k];

				// �����Ϸ��� ������ ���̴� 5�� ������� �ϸ�,
				if (age % 5 == 0)
				{
					// ������ 8ĭ�� ���̰� 1�� ������ �����Ѵ�.
					for (int dir = 0; dir < 8; dir++)
					{
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
						{
							// �� ĭ�� ���� ���� ������ �ɾ �Ǵϱ� �����ϴ�.
							a[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

// ��� �������ֱ�.
void Winter()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			energe[i][j] += insert_energe[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> insert_energe[i][j];
			energe[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, year;
		cin >> x >> y >> year;
		a[x][y].push_back(year);
	}

	for (int i = 0; i < K; i++)
	{
		SpringAndSummer();
		Fall();
		Winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans += a[i][j].size();
		}
	}

	cout << ans;
	return 0;
}