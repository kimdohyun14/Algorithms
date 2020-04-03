// ��ó : https://yabmoons.tistory.com/152
// �ణ ���� ���� ����..
// ������ BFSƲ�� ������ �˸� Ǯ���� ������ �ƴ� �����̴�.
// ���ο� ����� ����, ���߿� �ٽ� Ǯ���.
#include <iostream>
#include <queue>
#include <string>
#include <set>

#define MAX_SIZE 1000000 + 1
using namespace std;

string input;
int N, M, K;

// string -> integer
int invert(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum = sum + (s[i] - '0');
		if (i != s.length() - 1)
			sum = sum * 10;
	}
	return sum;
}

void bfs()
{
	queue<string> q;
	q.push(input);
	int cur_k = 0;
	int max = 0;

	while (q.empty() == 0 && cur_k < K)
	{
		int q_size = q.size();
		set<string> visited;

		for (int i = 0; i < q_size; i++)
		{
			string cur = q.front();
			q.pop();

			// 1 <= i < j <= M
			// 0 <= i < j <= M-1
			// i�� j�� ����.
			for (int j = 0; j < M - 1; j++)
			{
				for (int k = j + 1; k < M; k++)
				{
					// ������ ���� (�ٲ� ���� 0���� �����ϸ� �ȵȴ�.)
					if (j == 0 && cur[k] == '0') continue;

					swap(cur[j], cur[k]);
					// ������ ã������ �ִ��� Ȯ��
					if (visited.find(cur) == visited.end())
					{
						// ���� Ƚ���� k-1�̸鼭, ���� ū ���� ����
						if (cur_k == K - 1 && max < invert(cur))
							max = invert(cur);

						q.push(cur);
						visited.insert(cur);
					}
					swap(cur[j], cur[k]);
				}
			}
		}
		cur_k++;
	}

	if (cur_k != K)
		cout << -1 << '\n';
	else
		cout << max << '\n';
}

// �ٽ��� k�� �ٲ� �Ŀ� ���� ���� �� �ִ��� ã�� ���� ��ǥ��.
int main()
{
	cin >> input >> K;
	M = input.length();

	if (M == 1 || (M == 2 && invert(input) % 10 == 0))
		cout << -1 << '\n';
	else
		bfs();
	
	return 0;
}