#include <iostream>
using namespace std;

// Ÿ�� ä��� 3 (BOJ 14852)
long long d[1000001][2];

/*
�ð� �ʰ�
int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;
	if (memo[x] != 0) return memo[x];
	int result = 2 * dp(x - 1) + 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		result += (2 * dp(x - i)) % 1000000007;
	}
	return memo[x] = result % 1000000007;
}
*/

// 2���� ���̳��� ���α׷����� ����� �̿��ؼ� �ذ��Ѵ�.
long long dp(int x) {
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % 1000000007;
		d[i][0] = ( 3 * d[i-2][0] + 2 * d[i-1][0] + 2*d[i][1]) % 1000000007;
	}
	return d[x][0];
}

int main() {
	int n;
	cin >> n;
	cout << dp(n);
	return 0;
}