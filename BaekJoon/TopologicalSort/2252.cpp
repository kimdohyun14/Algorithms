#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001
using namespace std;

int N, M;
int inDegree[MAX];
vector<int> mp[MAX];
queue<int> q;

void topological(void) {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		int cycle = mp[cur].size();
		for (int i = 0; i < cycle; i++) {
			int nx = mp[cur][i];
			/* ���� ���� ���� */
			inDegree[nx]--;
			/* ���� ������ 0�̸� */
			if (inDegree[nx] == 0) {
				q.push(nx);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		mp[u].push_back(v);
		/* ���� ���� ���� */
		inDegree[v]++;
	}

	for (int i = 1; i <= N; i++) {
		/* ���� ������ 0�� �������� ť�� �ֱ� */
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	topological();
	return 0;
}