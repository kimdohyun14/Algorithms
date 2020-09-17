#include <bits/stdc++.h>
using namespace std;

int n, k;
int result;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (n >= k) {
		// n�� k�� ������ �������� �ʴ´ٸ� 1�� ����
		while (n % k != 0) {
			n--;
			result++;
		}

		// k�� ������
		n /= k;
		result++;
	}

	// ���������� ���� ���� ���ؿ� 1�� ����
	while (n > 1) {
		n--;
		result++;
	}

	cout << result << '\n';
	return 0;
}