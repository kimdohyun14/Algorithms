#include <iostream>
using namespace std;

int d[1001]; // d[i] : 2 x i Ÿ�ϸ��� ä��� ����� ��

int solve(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (d[n]) return d[n]; // memoization
	else
	{
		d[n] = (2 * solve(n - 2) + solve(n - 1)) % 10007;
	}

	return d[n];
}


int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}