#include <iostream>
using namespace std;

int a[1001];
int d1[1001]; // d[i] : a[i]�� ���������� ������ lis ���� (�����ϴ� �κ� ����)
int d2[1001]; // d[i] : a[i]�� �������� ������ lis ���� (�����ϴ� �κ� ����)

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	// �����ϴ� �κ� ������ ��������.
	for (int i = 0; i < n; i++)
	{
		d1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d1[j] + 1 > d1[i])
				d1[i] = d1[j] + 1;
		}
	}

	// �����ϴ� �κ� ������ ��������.
	for (int i = n - 1; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (a[i] > a[j] && d2[j] + 1 > d2[i])
				d2[i] = d2[j] + 1;
		}
	}

	// ���� ���� + ���� ���� - 1(�ߺ��Ǵ� ��� ����)�� max�� �Ǵ� ���� ����.
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (d1[i] + d2[i] - 1 > ans)
			ans = d1[i] + d2[i] - 1;
	}

	cout << ans;
	return 0;
}