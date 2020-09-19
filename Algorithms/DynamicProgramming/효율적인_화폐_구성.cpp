#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	cin >> n >> m;

	// n���� ȭ�� ���� ������ �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// �� �� ���� ����� �����ϱ� ���� DP ���̺� �ʱ�ȭ
	vector<int> d(m + 1, 10001);

	// ���̳��� ���α׷���(���Ҿ�)
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			// (i - k)���� ����� ����� �����ϴ� ���
			if (d[j - arr[i]] != 10001) {
				d[j] = min(d[j], d[j - arr[i]] + 1);
			}
		}
	}

	// ���� ��� ���
	if (d[m] == 10001) // ���������� m���� ����� ����� ���� ���
		cout << -1 << '\n';
	else
		cout << d[m] << '\n';
	return 0;
}