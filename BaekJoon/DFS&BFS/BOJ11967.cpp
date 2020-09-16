// https://ijsilver.tistory.com/27
// ���߿� �ٽ� Ǯ���
#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> board[MAX][MAX];
bool light[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

void BFS() {
	while (1) {
		for (int i = 0; i < MAX; i++)
			fill(visited[i], visited[i] + MAX, false);

		queue<pair<int, int>> q;
		q.push({ 1,1 });
		visited[1][1] = true;
		light[1][1] = true;
		bool find = false;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// �ش� (x,y)���� light ų �� �ִ� ������ �� Ų��.
			if (!board[x][y].empty()) {
				for (int i = 0; i < board[x][y].size(); i++) {
					int nx = board[x][y][i].first;
					int ny = board[x][y][i].second;
					light[nx][ny] = true;
				}
				// ���� ������, �����.
				board[x][y].clear();
				// ���ο� �濡 ���� �״ٴ� �ǹ�
				find = true;
			}

			// �����¿� ���鼭 ������ ���� Ž���ؼ� ����.
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
				if (light[nx][ny] && !visited[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}

		// ���Ӱ� ������ ���� ���ٸ� Ż��
		// ������ ���� ���ٸ� ������ ���ư� �� ���� �����̴�.
		if (!find) break;
	}
	// ������ ���� ���� Ȯ��
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (light[i][j]) cnt++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		board[x][y].push_back({ a,b });
	}
	BFS();
	return 0;
}