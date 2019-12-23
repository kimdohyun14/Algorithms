#include <iostream>
using namespace std;

int a[1001];
int d[1001]; // d[i]: i��°�� ������ ���ҷ� ������ ���� �� �����ϴ� �κ� ������ ����

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}

		if (d[i] > ans)
			ans = d[i];
	}
	for (int i = 0; i < n; i++)
		cout << d[i] << ' ';
	cout << endl;

	cout << ans;
	return 0;
}