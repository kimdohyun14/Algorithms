#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int s;
int cnt[1001][1001];

void bfs(int screen, int board) {
	queue<pair<int, int>> q;
	q.push(make_pair(screen, board));
	memset(cnt, -1, sizeof(cnt));
	cnt[screen][board] = 0;
	while (!q.empty()) {
		int cur_screen = q.front().first;
		int cur_board = q.front().second;
		q.pop();

		// ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 ����
		if (cnt[cur_screen][cur_screen] == -1) {
			cnt[cur_screen][cur_screen] = cnt[cur_screen][cur_board] + 1;
			q.push(make_pair(cur_screen, cur_screen));
		}

		// Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
		if (cur_screen + cur_board <= s) {
			if (cnt[cur_screen + cur_board][cur_board] == -1) {
				cnt[cur_screen + cur_board][cur_board] = cnt[cur_screen][cur_board] + 1;
				q.push(make_pair(cur_screen + cur_board, cur_board));
			}
		}

		// ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
		if (cur_screen - 1 >= 0) {
			if (cnt[cur_screen - 1][cur_board] == -1) {
				cnt[cur_screen - 1][cur_board] = cnt[cur_screen][cur_board] + 1;
				q.push(make_pair(cur_screen - 1, cur_board));
			}
		}
	}
}

int main() {
	cin >> s;
	bfs(1, 0); // �����̰� �̹� ȭ�鿡 �̸�Ƽ�� 1���� �Է������Ƿ� 1���� ����
	
	// ���Ϸ��� �ϴ� ���� �̸�Ƽ�� S���� ���� ��, Ŭ�����忡 ��� ����Ǿ� �ִ����� �𸣹Ƿ�
	// �� �߿��� �ּڰ��� ã���ش�.
	int ans = 987654321;
	for (int i = 0; i <= s; i++) {
		if (cnt[s][i] != -1) {
			ans = ans > cnt[s][i] ? cnt[s][i] : ans;
		}
	}

	cout << ans;
	return 0;
}