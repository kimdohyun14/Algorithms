#include <bits/stdc++.h>
using namespace std;

int n, l, r, totalCount;
int graph[51][51];
int unions[51][51];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void process(int x, int y, int index) {
	// (x,y)�� ��ġ�� ����� ���� ������ ��� ����Ʈ
	vector<pair<int, int>> united;
	united.push_back({ x,y });

	queue<pair<int, int>> q;
	q.push({ x,y });
	unions[x][y] = index;
	int summary = graph[x][y]; // ���� ������ ��ü �α� ��
	int count = 1;  // ���� ������ ���� ��
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (unions[nx][ny] == -1) {
				int diff = abs(graph[nx][ny] - graph[x][y]);
				if (diff >= l && diff <= r) {
					q.push({ nx,ny });
					unions[nx][ny] = index;
					summary += graph[nx][ny];
					count++;
					united.push_back({ nx,ny });
				}
			}
		}
	}

	int temp = summary / count;
	for (int i = 0; i < united.size(); i++) {
		int x = united[i].first;
		int y = united[i].second;
		graph[x][y] = temp;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	// �� �̻� �α� �̵��� �� �� ���� ������ �ݺ�
	while (true) {
		for (int i = 0; i < n; i++) {
			fill(unions[i], unions[i] + n, -1);
		}
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (unions[i][j] == -1) {
					process(i, j, index);
					index++;
				}
			}
		}

		// ��� �α� �̵��� ���� ���
		if (index == n * n) break;
		totalCount++;
	}
	cout << totalCount << '\n';
	return 0;
}