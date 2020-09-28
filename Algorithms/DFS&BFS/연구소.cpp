#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8][8];
int temp[8][8];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int result;

// DFS�� �̿��� �� ���̷����� ������� �������� �ϱ�
void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// ��,��,��,�� �߿��� ���̷����� ���� �� �ִ� ���
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				// �ش� ��ġ�� ���̷��� ��ġ�ϰ�, �ٽ� �����
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

// ���� �ʿ��� ���� ������ ũ�⸦ ����ϴ� �޼���
int GetScore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				score++;
			}
		}
	}

	return score;
}

// DFS�� �̿��� ��Ÿ���� ��ġ�ϸ鼭, �� �� ���� ������ ũ�� ���
void DFS(int count) {
	// ��Ÿ���� 3�� ��ġ�� ���
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		// �� ���̷����� ��ġ���� ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i, j);
				}
			}
		}

		// ���� ������ �ִ밪 ���
		result = max(result, GetScore());
		return;
	}
	// �� ������ ��Ÿ���� ��ġ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				DFS(count + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0);
	cout << result << '\n';
	return 0;
}