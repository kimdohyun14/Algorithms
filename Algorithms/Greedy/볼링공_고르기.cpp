#include <bits/stdc++.h>
using namespace std;

int n, m;
// 1���� 10������ ���Ը� ���� �� �ִ� �迭
int arr[11];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;
	// 1���� m������ �� ���Կ� ���Ͽ� ó��
	for (int i = 1; i <= m; i++) {
		n -= arr[i]; // ���԰� i�� �������� ���� (A�� ������ �� �ִ� ����) ����
		result += arr[i] * n; // B�� �����ϴ� ����� ���� �����ֱ�
	}

	cout << result << '\n';
	return 0;
	return 0;
}