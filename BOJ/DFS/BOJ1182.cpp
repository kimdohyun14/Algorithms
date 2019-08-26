#include <iostream>
#include <vector>
using namespace std;

int n, s;
int ans;

void solve(const vector<int>& a, int i, int sum, int goal) {
	// ������ ���
	if (sum == goal && i == a.size()) {
		ans += 1;
		return;
	}
	// �Ұ����� ���
	if (i == a.size() && sum != goal) {
		return;
	}

	// ������ ���
	solve(a, i + 1, sum + a[i], goal);
	solve(a, i + 1, sum, goal);
}

int main() {
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	solve(v, 0, 0, s);
	// ���� 0�϶� ��, ��� ��츦 �������� ���� ��찡 �����ϹǷ�
	// ������ ��쿡�� -1�� ���ش�. (�������̹Ƿ�)
	if (s == 0) {
		cout << ans - 1;
	}
	else {
		cout << ans;
	}
	return 0;
}