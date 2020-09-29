#include <bits/stdc++.h>
using namespace std;

int n;
char board[6][6];
vector<pair<int, int>> teachers;
vector<pair<int, int>> spaces;

bool found; // �л��� �� �� �������� �ʵ��� ��ġ�� �� �ִ����� ����

// Ư�� �������� ���ø� ���� (�л� �߰�: true, �л� �̹߰�: false)
bool watch(int x, int y, int direction) {
	// ���� �������� ����
	if (direction == 0) {
		while (y >= 0) {
			// �л��� �ִ� ���
			if (board[x][y] == 'S') return true;
			// ��ֹ��� �ִ� ���
			if (board[x][y] == 'O') return false;
			y--;
		}
	}
	// ������ �������� ����
	if (direction == 1) {
		while (y < n) {
			// �л��� �ִ� ���
			if (board[x][y] == 'S') return true;
			// ��ֹ��� �ִ� ���
			if (board[x][y] == 'O') return false;
			y++;
		}
	}
	// ���� �������� ����
	if (direction == 2) {
		while (x >= 0) {
			// �л��� �ִ� ���
			if (board[x][y] == 'S') return true;
			// ��ֹ��� �ִ� ���
			if (board[x][y] == 'O') return false;
			x--;
		}
	}
	// �Ʒ��� �������� ����
	if (direction == 3) {
		while (x < n) {
			// �л��� �ִ� ���
			if (board[x][y] == 'S') return true;
			// ��ֹ��� �ִ� ���
			if (board[x][y] == 'O') return false;
			x++;
		}
	}
	return false;
}

// ��ֹ� ��ġ ���Ŀ�, �� ���̶� �л��� �����Ǵ��� �˻�
bool process() {
	// ��� ������ ��ġ�� �ϳ��� Ȯ��
	for (int i = 0; i < teachers.size(); i++) {
		int x = teachers[i].first;
		int y = teachers[i].second;
		// 4���� �������� �л��� ������ �� �ִ��� Ȯ��
		for (int j = 0; j < 4; j++) {
			if (watch(x, y, j)) return true;
		}
	}
	return false;
}



int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T') teachers.push_back({ i,j });
			else if (board[i][j] == 'X') spaces.push_back({ i,j });
		}
	}

	// �� �������� 3���� �̴� ��� ������ Ȯ��
	vector<int> order(spaces.size());
	fill(order.end() - 3, order.end(), 1);
	do {
		// ��ֹ����� ��ġ�غ���
		for (int i = 0; i < spaces.size(); i++) {
			if (order[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'O';
			}
		}

		// �л��� �� �� �������� �ʴ� ���
		if (!process()) {
			// ���ϴ� ��츦 �߰��� ��
			found = true;
			break;
		}

		// ��ġ�� ��ֹ��� �ٽ� ���ֱ�
		for (int i = 0; i < spaces.size(); i++) {
			if (order[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'X';
			}
		}
	} while (next_permutation(order.begin(), order.end()));

	if (found) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}