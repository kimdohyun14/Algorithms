#include <iostream>
using namespace std;

#define MOD 10007

int d[1001][10]; // d[N][i] : ���̰� N�� ������ ��, ���� �������� ���� ���ڴ� i

int main()
{
	int n;
	cin >> n;

	// ���̰� 1�� ���� ���帷 ��
	for (int i = 0; i <= 9; i++)
		d[1][i] = 1;

	// ��ư� 2�̻��� ���帷 �� ���ϱ�
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
				d[i][j] %= MOD;
			}

	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];

	cout << ans % MOD;
	return 0;
}