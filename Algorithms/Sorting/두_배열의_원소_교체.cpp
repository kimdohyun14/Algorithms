#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, b;

int main() {
	cin >> n >> k;
	// �迭 a�� ��� ���Ҹ� �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	// �迭 b�� ��� ���Ҹ� �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	// �迭 a�� �������� ���� ����
	sort(a.begin(), a.end());
	// �迭 b�� �������� ���� ����
	sort(b.begin(), b.end(), greater<int>());;

	// ù ��° �ε������� Ȯ���ϸ�, �� �迭�� ���Ҹ� �ִ� k�� ��
	for (int i = 0; i < k; i++) {
		// a�� ���Ұ� b�� ���Һ��� ���� ���
		if (a[i] < b[i]) swap(a[i], b[i]);
		// a�� ���Ұ� b�� ���Һ��� ũ�ų� ���� ��, Ż��
		else break;
	}

	// �迭 a�� ��� ������ ���� ���
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		result += a[i];
	}

	cout << result << '\n';
	return 0;
}