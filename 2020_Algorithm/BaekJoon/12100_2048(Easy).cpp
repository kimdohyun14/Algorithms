// https://yabmoons.tistory.com/230

// �������� ��ٷο� ���������� ���ؼ��� ��Ʊ⸸�ϴ�..
// �ߺ� ���� ������ �ٽ� �� �� ��������.
// ���߿� �ٽ� Ǯ���.

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20;

int N, answer;
int stage[MAX][MAX];
int copy_stage[MAX][MAX];
bool visited[MAX][MAX];
int choice[5];

void CopyStage()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copy_stage[i][j] = stage[i][j];
		}
	}
}

int FindMaxValue()
{
	int max_value = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			max_value = max(max_value, copy_stage[i][j]);
		}
	}

	return max_value;
}

void MoveRight()
{
	// ���������� ����� �� �ű��
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = j - 1;
				while (k >= 0)
				{
					if (copy_stage[i][k] != 0)
					{
						check = true;
						break;
					}
					k--;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[i][k];
					copy_stage[i][k] = 0;
				}
			}
		}
	}

	/* �� ���� �����ʺ��� ���� ��ǥ�� -1 �� ���� ������ üũ �Ŀ� 
	   ������ �����ְ�, ĭ�� �����ش�.*/
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (copy_stage[i][j] == copy_stage[i][j - 1])
			{
				copy_stage[i][j] = copy_stage[i][j] * 2;
				copy_stage[i][j - 1] = 0;
			}
		}
	}

	// ���������� ����� �� �ű��
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = j - 1;
				while (k >= 0)
				{
					if (copy_stage[i][k] != 0)
					{
						check = true;
						break;
					}
					k--;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[i][k];
					copy_stage[i][k] = 0;
				}
			}
		}
	}
}

void MoveLeft()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = j + 1;
				while (k <= N - 1)
				{
					if (copy_stage[i][k] != 0)
					{
						check = true;
						break;
					}
					k++;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[i][k];
					copy_stage[i][k] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (copy_stage[i][j] == copy_stage[i][j + 1])
			{
				copy_stage[i][j] = copy_stage[i][j] * 2;
				copy_stage[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = j + 1;
				while (k <= N - 1)
				{
					if (copy_stage[i][k] != 0)
					{
						check = true;
						break;
					}
					k++;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[i][k];
					copy_stage[i][k] = 0;
				}
			}
		}
	}
}

void MoveDown()
{
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = i - 1;
				while (k >= 0)
				{
					if (copy_stage[k][j] != 0)
					{
						check = true;
						break;
					}
					k--;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[k][j];
					copy_stage[k][j] = 0;
				}
			}
		}
	}

	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (copy_stage[i][j] == copy_stage[i - 1][j])
			{
				copy_stage[i][j] = copy_stage[i][j] * 2;
				copy_stage[i - 1][j] = 0;
			}
		}
	}

	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = i - 1;
				while (k >= 0)
				{
					if (copy_stage[k][j] != 0)
					{
						check = true;
						break;
					}
					k--;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[k][j];
					copy_stage[k][j] = 0;
				}
			}
		}
	}
}

void MoveUp()
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = i + 1;
				while (k <= N - 1)
				{
					if (copy_stage[k][j] != 0)
					{
						check = true;
						break;
					}
					k++;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[k][j];
					copy_stage[k][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (copy_stage[i][j] == copy_stage[i + 1][j])
			{
				copy_stage[i][j] = copy_stage[i][j] * 2;
				copy_stage[i + 1][j] = 0;
			}
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool check = false;
			if (copy_stage[i][j] == 0)
			{
				int k = i + 1;
				while (k <= N - 1)
				{
					if (copy_stage[k][j] != 0)
					{
						check = true;
						break;
					}
					k++;
				}
				if (check == true)
				{
					copy_stage[i][j] = copy_stage[k][j];
					copy_stage[k][j] = 0;
				}
			}
		}
	}
}

void Simulation()
{
	for (int i = 0; i < 5; i++)
	{
		int dir = choice[i];
		if (dir == 0) MoveRight();
		else if (dir == 1) MoveLeft();
		else if (dir == 2) MoveDown();
		else if (dir == 3) MoveUp();
	}

	answer = max(answer, FindMaxValue());
}

void SelectDirection(int index, int cnt)
{
	if (cnt == 5)
	{
		CopyStage();
		Simulation();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		choice[cnt] = i;
		SelectDirection(i, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> stage[i][j];
		}
	}

	SelectDirection(0, 0);
	cout << answer;
	return 0;
}