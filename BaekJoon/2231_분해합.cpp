#include <iostream>

#define MAX 1000000
using namespace std;

int calc(int num)
{
	int sum = num;
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int main()
{
	int n;
	cin >> n;

	bool find = false;
	for (int i = 1; i <= MAX; i++)
	{
		//cout << i << "�� �������� " << calc(i) << endl;
		if (n == calc(i))
		{
			//cout << "������ " << i << "�Դϴ�." << endl;
			cout << i << '\n';
			find = true;
			break;
		}
	}

	// ������ ã�� ���ߴٸ�
	if (!find)
	{
		cout << 0 << '\n';
	}
	return 0;
}