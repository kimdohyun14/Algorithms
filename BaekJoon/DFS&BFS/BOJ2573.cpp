#include <bits/stdc++.h>
using namespace std;

int board[301][301];
int copy_board[301][301];
bool visited[301][301];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
int n, m;

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny] || board[nx][ny] == 0) continue;
		DFS(nx, ny);
	}
}

int GetComponent() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > 0 && !visited[i][j]) {
				DFS(i, j);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int year = 0;
	while (1) {
		year++;

		for (int i = 0; i < n; i++)
			fill(visited[i], visited[i] + m, false);

		// ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copy_board[i][j] = board[i][j];
			}
		}

		// ������ ���̱�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] > 0) {
					int cnt = 0;
					// �ش� ������ �������� �����¿� �ٴ����� Ȯ��
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (board[nx][ny] == 0) cnt++;
					}

					// ���� - �������ִ� �ٴ��� ��
					copy_board[i][j] -= cnt;
					if (copy_board[i][j] < 0) copy_board[i][j] = 0;
				}
			}
		}
		
		// ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = copy_board[i][j];
			}
		}

		// ������ �� ��� �̻����� �ɰ������� Ȯ��
		int cnt = GetComponent();
		if (cnt > 1) {
			cout << year;
			break;
		}
		// ������ �� ��� �������� �̰��� ����ó��
		if (cnt == 0) {
			cout << 0;
			break;
		}
	}
	return 0;
}