#include <iostream>
#include <algorithm>
using namespace std;

int d1[100001];
int d2[100001];
int a[100001];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// ����ó��
	if (n == 1)
	{
		cout << a[0];
		return 0;
	}

	// ���ʿ��� ���������� ������ ���ϱ�
	int ans = -1000;
	d1[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		d1[i] = max(a[i], d1[i - 1] + a[i]);
		if (d1[i] > ans)
			ans = d1[i];
	}

	// �����ʿ��� �������� ������ ���ϱ�
	d2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		d2[i] = max(a[i], d2[i + 1] + a[i]);
	}

	// i��°�� �������� �������� ���� �ִ밪 ã��
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			ans = max(ans, d2[i + 1]);
			continue;
		}
		if (i == n - 1)
		{
			ans = max(ans, d1[i - 2]);
			continue;
		}

		ans = max(ans, d1[i - 1] + d2[i + 1]);
	}

	cout << ans;
	return 0;
}