#include <bits/stdc++.h>
using namespace std;

// ���� Ʋ�� ����, 0�ʿ� 1���� BFS�� ��������.
// ���� ������ ã�Ҵ��� �ð��� �ٸ� �� �ִ�.
// �׷��� ������ time�̶�� ������ �߰��� �����ؾ� �Ѵ�.
const int MAX = 200002;
int N, K;
bool dist[MAX];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fill(dist, dist + MAX, false);
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		if (cur == K) {
			cout << time;
			break;
		}

		// �����̵�
		if (cur * 2 < MAX && !dist[cur * 2]) {
			dist[cur * 2] = true;
			q.push({ cur * 2, time });
		}

		if (cur - 1 >= 0 && !dist[cur - 1]) {
			dist[cur - 1] = true;
			q.push({ cur - 1, time + 1 });
		}

		if (cur + 1 < MAX && !dist[cur + 1]) {
			dist[cur + 1] = true;
			q.push({ cur + 1,time + 1 });
		}
	}

	return 0;
}