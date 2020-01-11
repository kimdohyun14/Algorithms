#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int a[1000][1000]; // �丶�� �����̸鼭 ���ÿ� ��¥�� ������ ������.
bool check[1000][1000]; // �湮����
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(queue<pair<int,int>>& tomato) {

	while (!tomato.empty()) {
		int size = tomato.size();
		for (int i = 0; i < size; i++) {
			int cx = tomato.front().first;
			int cy = tomato.front().second;
			tomato.pop();
			check[cx][cy] = true;
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (a[nx][ny] == 0 && check[nx][ny] == false) {
						a[nx][ny] = a[cx][cy] + 1;
						tomato.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	queue<pair<int, int>> tomato;
	// �丶���� ���¸� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			// �丶���� ���� ��ġ ����
			if (a[i][j] == 1) {
				tomato.push(make_pair(i, j));
			}
		}
	}

	// �丶�� ����
	bfs(tomato);

	// ���ϸ��� �;����� Ȯ��
	// �� ���� ������ �丶�䰡 �ִ��� Ȯ��
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				ok = false;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = ans > a[i][j] ? ans : a[i][j];
		}
	}

	if (ok)
		cout << ans - 1;
	else
		cout << -1;

	return 0;
}