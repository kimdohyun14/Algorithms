#include <iostream>
#include <algorithm>
using namespace std;

int a[2][100001]; // 2*N�� ũ�� ��ƼĿ�� ������ ����ִ� ����
int d[100001][3]; // d[n][k] : 2*N���� ���� �� �ִ� �ִ� ����
                  // k = 0 �̸� ��ƼĿ�� ���� ���� ���
				  // k = 1 �̸� ���� ��ƼĿ�� ���� ���
                  // k = 2 �̸� �Ʒ��� ��ƼĿ�� ���� ���
int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n;
		cin >> n;

		// initialize
		for (int j = 0; j < 100001; j++)
			for (int k = 0; k < 3; k++)
				d[j][k] = 0;

		// input (2 * N matrix)
		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= n; k++)
				cin >> a[j][k];

		
		for (int j = 1; j <= n; j++)
		{
			// ��ƼĿ�� ����� ���� ���
			d[j][0] = max(d[j - 1][0], max(d[j - 1][1], d[j - 1][2]));
			
			// ���� ��ƼĿ�� ��� ���
			d[j][1] = max(d[j - 1][0], d[j - 1][2]) + a[0][j];
			
			// �Ʒ��� ��ƼĿ�� ��� ���
			d[j][2] = max(d[j - 1][0], d[j - 1][1]) + a[1][j];
		}

		// output
		int ans = max(d[n][0], max(d[n][1], d[n][2]));
		cout << ans << '\n';
	}
	return 0;
}