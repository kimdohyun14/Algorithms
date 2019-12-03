#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int T[16];
int P[16];

void solve(int sum, int day)
{
	// �Ұ����� ���
	if (day > n + 1)
		return;

	// ������ ���
	if (day == n + 1)
	{
		if (sum > ans)
			ans = sum;

		return;
	}

	// ���� ���
	solve(sum + P[day], day + T[day]); // day�� ����� �ϴ� ���
	solve(sum, day + 1);               // day�� ����� ���� �ʴ� ���
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		T[i] = t, P[i] = p;
	}

	solve(0, 1);
	cout << ans;
	return 0;
}