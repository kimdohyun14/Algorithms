#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1001][1001];
bool visited[1001][1001][2]; // [x][y][���� �μ� Ƚ��]

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int BFS()
{
	// (x, y, ���� �μ� Ƚ��, ī��Ʈ)
	queue<tuple<int, int, int, int>> q;
	q.push({ 0,0,0,1 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int b = get<2>(q.front());
		int cnt = get<3>(q.front());
		q.pop();

		if (x == n - 1 && y == m - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			// ���� �̵��Ϸ��� ĭ�� ���̰�, ���� ���� �μ��� �ʾҴٸ�
			if (board[nx][ny] == 1 && b == 0) {
				// ���� �μ��� �̵�
				visited[nx][ny][b + 1] = true;
				q.push({ nx,ny,b + 1,cnt + 1 });
			}
			// ���� �̵��Ϸ��� ĭ�� ��ĭ�̰�, ���� �μ��� �Դ���, �ƴ���������
			// �湮�� ������ �н��ϰ�, �ƴ϶�� �������� �����Ѵ�.
			if (board[nx][ny] == 0 && visited[nx][ny][b] == false) {
				visited[nx][ny][b] = true;
				q.push({ nx,ny,b,cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			board[i][j] = str[j] - '0';
		}
	}

	cout << BFS() << '\n';
	return 0;
}