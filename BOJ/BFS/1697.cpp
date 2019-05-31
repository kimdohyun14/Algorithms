#include <iostream>
#include <queue>
#define MAX 200002
using namespace std;

int visit[MAX];
int path[MAX];
int N, K;
int mv[] = { -1,1 };

int bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int cx = q.front();
		q.pop();
		/* ������ ã������ */
		if (cx == K) break;
		/* �� 3���� ��Ʈ */
		for (int i = 0; i < 2; i++) {
			int nx = cx + mv[i];
			if (0 <= nx && nx <= 200000) {
				if (visit[nx] == 0) {
					visit[nx] = 1;
					path[nx] = path[cx] + 1;
					q.push(nx);
				}
			}
		}
		int nx = cx * 2;
		if (0 <= nx && nx <= 200000) {
			if (visit[nx] == 0) {
				visit[nx] = 1;
				path[nx] = path[cx] + 1;
				q.push(nx);
			}
		}
	}
	return path[K];
}

int main()
{
	/* ������ ��ġ�� ������ ��ġ */
	cin >> N >> K;
	cout << bfs(N);
	return 0;
}