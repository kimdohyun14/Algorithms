#include <iostream>
using namespace std;

long long d[1000001]; // d[i] : i�� 1,2,3�� ������ ��Ÿ���� ����� ��

// O(N)
long long solve(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (d[n]) return d[n]; // memoization
	else
	{
		d[n] = (solve(n - 1) + solve(n - 2) + solve(n - 3)) % 1000000009;
	}

	return d[n];
}

int main()
{
	int tc, n;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}