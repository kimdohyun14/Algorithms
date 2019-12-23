#include <iostream>
using namespace std;

int a[1001]; // ������ ���� ���� �迭
int d[1001]; // d[i] : i��°�� ������ ���ҷ� ������ lis�� ����
int v[1001]; // a[i]�� �տ� �;� �ϴ� ���� �ε���

// lis�� �κ� ���� ���
void recursive(int p)
{
	if (p == -1) return;
	recursive(v[p]);
	cout << a[p] << ' ';
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v[i] = -1;
	}
		
	int max_idx = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}

		if (d[i] > max)
		{
			max = d[i];
			max_idx = i;
		}
			
	}
	cout << max << '\n';
	recursive(max_idx);
	return 0;
}