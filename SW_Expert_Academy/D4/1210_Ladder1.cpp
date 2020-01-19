#include <iostream>
#include <cstring>
using namespace std;

int a[101][101];
int finish_y;
int answer = 0;


int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int cycle;
		cin >> cycle;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> a[i][j];
				// ���������� ��ǥ ���.
				if (a[i][j] == 2)
				{
					finish_y = j;
				}
			}
		}

		// ���������������� ����ؼ� ��� ������ ã�´�.
		for (int i = 99; i >= 0; i--)
		{
			// �߿��� ���� �ö���鼭, �����̳� ������ ������ ������ �װ����� �̵��Ѵ�.
			// �켱 ���ʿ� ���� �ִٸ�
			if (a[i][finish_y - 1] == 1)
			{
				while (true)
				{
					finish_y--; // �������� �̵��ϰ�
					if (a[i][finish_y - 1] == 0) // �ٽ� Ȯ��
						break;
				}
			}
			// �����ʿ� ���� �ִٸ�
			else if (a[i][finish_y + 1] == 1)
			{
				while (true)
				{
					finish_y++; // ���������� �̵��ϰ�
					if (a[i][finish_y + 1] == 0)
						break;
				}
			}
		}

		cout << "#" << test_case << " " << finish_y << endl;
	}
	return 0;
}