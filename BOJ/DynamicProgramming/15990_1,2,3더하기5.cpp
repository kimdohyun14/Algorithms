#include <iostream>
using namespace std;

#define MOD 1000000009
#define LIMIT 100000

long long d[100001][4]; // d[i][j] : i�� 1,2,3�� ������ ��Ÿ���� ����� ��, �� j�� �������� ����� ����� �ϸ�

int main()
{
	// �̸� ���� �� ���س��´�.
	d[1][1] = d[2][2] = d[3][3] = 1;
	d[3][1] = d[3][2] = 1;
	for (int i = 4; i <= LIMIT; i++)
	{
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % MOD;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % MOD;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % MOD;
	}

	// �����ذ�
	int tc, n;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3]) % MOD << '\n';
	}

	return 0;
}