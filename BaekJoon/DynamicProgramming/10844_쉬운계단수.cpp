#include <iostream>
using namespace std;

#define MOD 1000000000

int d[101][10]; // d[n][i] : ���̰� N�� ��� ��, �������� ���� �� i

int main()
{
	int n;
	cin >> n;

	// ���̰� 1�� ��� ��
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	// ���̰� 2�� ��� ��
	for (int i = 2; i <= n; i++)
	{
		// ���� �ڿ� ���� ���� 0 ~ 9
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 >= 0)
				d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9)
				d[i][j] += d[i - 1][j + 1];

			d[i][j] %= MOD;
		}
	}

	// �ش� ���̰� N�� ���� ��� ��� ���� ���ϸ�
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];

	cout << ans % MOD;
	return 0;
}