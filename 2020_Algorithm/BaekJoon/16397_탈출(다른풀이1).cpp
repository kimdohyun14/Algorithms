// ��ó : https://jaimemin.tistory.com/979
// B ��ư�� �����ϴ� ������ �� �����ϰ�, �޸� ȿ������ ���� �� ����.
#include <iostream>
#include <queue>
#define MAX_SIZE 100000
using namespace std;

int N, T, G;
bool visited[MAX_SIZE];

int bfs()
{
	queue<pair<int, int>> q; // (����, �õ�Ƚ��)
	q.push({ N, 0 });
	visited[N] = true;
	while (!q.empty())
	{
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();

		// �ִ� �õ�Ƚ���� �ʰ��ϸ� Ż�� �Ұ�
		if (cost > T) break;

		// ��ǥġ�� G�� �����ϸ� ���
		if (here == G) return cost;

		// �� ���� ��ư�� �������.
		// A ��ư
		int A = here + 1;
		if (A < MAX_SIZE && !visited[A])
		{
			visited[A] = true;
			q.push({ A, cost + 1 });
		}

		// B ��ư
		int next = here * 2;
		if (next >= MAX_SIZE) continue;
		int B = next;
		int digit = 1; // �ִ� �ڸ���
		while (next)
		{
			next /= 10;
			digit *= 10;
		}
		digit /= 10;
		B -= digit;
		if (B < MAX_SIZE && !visited[B])
		{
			visited[B] == true;
			q.push({ B, cost + 1 });
		}
	}

	return -1; // Ż�⿡ ������ ���
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T >> G;

	int ret = bfs();
	if (ret == -1)
		cout << "ANG\n";
	else
		cout << ret << '\n';

	return 0;
}