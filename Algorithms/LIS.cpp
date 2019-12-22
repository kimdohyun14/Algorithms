#include <iostream>
using namespace std;

/* 
	LIS �˰��� (Longest Incresing Subsequence) ���������κм��� 

	�����ϴ� ������� ���ڸ� ���鼭 �� �κ� ������ ���̰� �ִ� ���̰� �ǵ��� ����

	������ȹ�� �� �ϳ��� ��ũ��
	O(N^2) ���߷���
	O(NlogN) ���׸�Ʈ Ʈ�� �������, �̺� Ž�� �������
*/

// O(N^2) �������
int a[1001];
int d[1001]; // d[i] : i��° ���� ������ ���ҷ� ������ LIS�� ���� (����)

int main()
{
	int n;
	cin >> n;

	// INPUT
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		// i�� �������� (0 ~ i - 1)���� üũ
		for (int j = 0; j < i; j++)
		{
			// ���� �� �κ��� �����Ѵ�.
			if (a[i] > a[j] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}

		if (d[i] > maxLength) 
			maxLength = d[i];
	}

	// OUTPUT
	cout << maxLength;
	return 0;
}