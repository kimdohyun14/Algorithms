#include <iostream>
using namespace std;

int main()
{
	int cycle;

	for (int test_case = 1; test_case <= 10; test_case++)
	{
		cin >> cycle;
		int arr[100][100] = { 0, };
		int row_sum = 0;  // ���� ��
		int col_sum = 0;  // ���� ��
		int dia_sum = 0;  // �밢���� ��

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];

		// �� ���� �� ���ؼ� ���� ū ���� �� �����ϱ�.
		for (int i = 0; i < 100; i++)
		{
			int sum = 0;
			for (int j = 0; j < 100; j++)
			{
				sum += arr[i][j];
			}

			row_sum = row_sum > sum ? row_sum : sum;
		}

		// �� ���� �� ���ؼ� ���� ū ���� �� �����ϱ�.
		for (int j = 0; j < 100; j++)
		{
			int sum = 0;
			for (int i = 0; i < 100; i++)
			{
				sum += arr[i][j];
			}

			col_sum = col_sum > sum ? col_sum : sum;
		}

		// �� �밢���� �� ���ؼ� ���� ū �밢���� �� �����ϱ�.
		
		// ���� �밢���� �� ���ϱ�
		int sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += arr[i][99 - i];
		}

		dia_sum = dia_sum > sum ? dia_sum : sum;

		
		// ���� �밢���� �� ���ϱ�
		sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += arr[i][i];
		}

		dia_sum = dia_sum > sum ? dia_sum : sum;

		int answer = row_sum;

		answer = answer > col_sum ? answer : col_sum;
		answer = answer > dia_sum ? answer : dia_sum;
		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}