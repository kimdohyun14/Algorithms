#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int arr[101][101];
vector<pair<int, char>> info; // ���� ȸ�� ����

// ó������ �������� ���� �����Ƿ�(��, ��, ��, ��)
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int turn(int direction, char c) {
	if (c == 'L') direction = (direction == 0) ? 3 : direction - 1;
	else direction = (direction + 1) % 4;
	return direction;
}

int simulate() {
	int x = 1, y = 1; // ���� �Ӹ� ��ġ
	arr[x][y] = 2; // ���� �����ϴ� ��ġ�� 2�� ǥ��
	int direction = 0; // ó������ ������ ���� ����
	int time = 0; // ������ �ڿ� ���� '��' �ð�
	int index = 0; // ������ ȸ���� ����
	queue<pair<int, int> > q; // ���� �����ϰ� �ִ� ��ġ ����(������ ����)
	q.push({ x, y });

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		// �� ���� �ȿ� �ְ�, ���� ������ ���� ��ġ���
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny] != 2) {
			// ����� ���ٸ� �̵� �Ŀ� ���� ����
			if (arr[nx][ny] == 0) {
				arr[nx][ny] = 2;
				q.push({ nx, ny });
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				arr[px][py] = 0;
			}
			// ����� �ִٸ� �̵� �Ŀ� ���� �״�� �α�
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
		// ���̳� ���� ����� �ε����ٸ�
		else {
			time += 1;
			break;
		}
        // ���� ��ġ�� �Ӹ��� �̵�
        x = nx;
        y = ny;
        time += 1;
        if (index < l && time == info[index].first) { // ȸ���� �ð��� ��� ȸ��
            direction = turn(direction, info[index].second);
            index += 1;
        }
	}
	return time;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> k;

	// �� ����(��� �ִ� ���� 1�� ǥ��)
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	// ���� ȸ�� ���� �Է�
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		info.push_back({ x, c });
	}

	cout << simulate() << '\n';
	return 0;
}