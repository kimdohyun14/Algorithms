#include <bits/stdc++.h>
using namespace std;

#define MAX 7

int n;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
char m[MAX][MAX];
vector<pair<int, int>> v, t;

bool found;

// �����Ե��� �л����� ������ �� �ִ���
// ������ �� �ִٸ� true
// �������� �� �Ѵٸ� false
bool check(pair<int, int> pt) {
	for (int i = 0; i < 4; i++) {
		int x = pt.first;
		int y = pt.second;
		while (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < n) {
			x = x + dx[i];
			y = y + dy[i];
			// ��ֹ��̸� �� �̻� ���� �Ұ���
			if (m[x][y] == '0') break;
			// �л��� �߰������� �ٷ� true(������ �� �ִٴ� �ǹ�)
			else if (m[x][y] == 'S') return true;
		}
	}
	return false;
}

void simulate(int len, int idx) {
	if (len == 3) {
		for (auto i : t) {
			// �����Ե��� �� 1���̶� ������ �� �ִٸ� return
			if (check(i)) return;
		}

		// �����Ե��� 1���̶� �������� �� �Ѵٸ� ����
		found = true;
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		m[v[i].first][v[i].second] = '0'; // ��ֹ� ��ġ
		simulate(len + 1, i + 1);
		m[v[i].first][v[i].second] = 'X'; // ��ֹ� ����
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'X') v.push_back({ i,j });
			else if (m[i][j] == 'T') t.push_back({ i,j });
		}
	}

	simulate(0, 0);
	if (found) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}