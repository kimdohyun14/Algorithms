#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];

int solve(int n)
{
	if (n == 1) return 0;

	// memoization
	if (d[n]) return d[n];

	// �ϴ� 1�� ���� ����. (���⼭�� ���� �ּҰ��̶� �����ϰ� �����ϴ� ���)
	d[n] = solve(n - 1) + 1;

	if (n % 3 == 0)
		d[n] = min(d[n], solve(n / 3) + 1); // ������ ���� d[n]�� 3���� ���� ���� ���ؼ� �� ���� ���� �����Ѵ�.

	if (n % 2 == 0)
		d[n] = min(d[n], solve(n / 2) + 1);

	return d[n];
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}