#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int N, K, cnt, min_time;
bool visited[MAX];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	fill(visited, visited + MAX, false);

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		// �ٽ��� ť�� ���� ���� ��, �湮 ������ ǥ���ϴ� ���� �ƴ�,
		// pop�� �� ��, �湮 ������ ǥ���ϸ� ���� ���� ����� ���� ���� �� �� �ִ�.
		visited[cur] = true;

		// �̹� �������� �ѹ� �������� ���
		if (min_time && min_time == time && cur == K) cnt++;

		// ���ʷ� ������ ���޽� �ּ� �ð� ����ϰ� cnt++
		if (!min_time && cur == K) {
			min_time = time;
			cnt++;
		}

		if (cur + 1 < MAX && !visited[cur + 1]) {
			q.push({ cur + 1,time + 1 });
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({ cur - 1,time + 1 });
		}
		if (cur * 2 < MAX && !visited[cur * 2]) {
			q.push({ cur * 2, time + 1 });
		}
	}

	cout << min_time << '\n' << cnt << '\n';
	return 0;
}