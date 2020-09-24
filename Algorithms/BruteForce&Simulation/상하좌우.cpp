#include <bits/stdc++.h>
using namespace std;

int n;
string plans;
int x = 1, y = 1;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char moveTypes[] = { 'L','R','U','D' };

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin.ignore(); // ���� ���� (���⼭�� Enter)
	getline(cin, plans);
	// �̵� ��ȹ�� �ϳ��� Ȯ��
	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; j++) {
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}

		// ������ ����� ��� ����
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		// �̵� ����
		x = nx;
		y = ny;
	}

	cout << x << ' ' << y << '\n';
	return 0;
}