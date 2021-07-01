#include <iostream>
using namespace std;

const int SIZE = 10;
// backtracking
// ������ �ٽ� Ǯ���
int board[SIZE][SIZE];
bool chk1[SIZE][SIZE]; // ���� üũ
bool chk2[SIZE][SIZE]; // ���� üũ
bool chk3[SIZE][SIZE]; // 3 x 3 üũ

void dfs(int cnt) {
	int x = cnt / 9;
	int y = cnt % 9;

	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		// ��Ʈ��ŷ�� ��� �������� ������� ���� ����� �� �ִµ�,
		// �� ����� ����ϸ� ���α׷� ������ ������ ���ش�.
		// �� ������ Ž������ ���� �ٷ� ���α׷� ����
		exit(0); 
	}

	if (board[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			// x�࿡�� 0 ~ 9 Ȯ��
			// y������ 0 ~ 9 Ȯ��
			// 3 x 3 Ȯ��
			if (chk1[x][i] == false && chk2[y][i] == false && chk3[(x / 3) * 3 + (y / 3)][i] == false) {
				chk1[x][i] = true;
				chk2[y][i] = true;
				chk3[(x / 3) * 3 + (y / 3)][i] = true;
				board[x][y] = i;
				dfs(cnt + 1);
				chk1[x][i] = false;
				chk2[y][i] = false;
				chk3[(x / 3) * 3 + (y / 3)][i] = false;
				board[x][y] = 0;
			}
		}
	}
	else
		dfs(cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0) {
				chk1[i][board[i][j]] = true;
				chk2[j][board[i][j]] = true;
				chk3[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}