#include <iostream>
using namespace std;

int main()
{
	double n = 12.34567;
	cout.precision(2); // ���� ū �ڸ������� 2�ڸ� ���
	cout << n << '\n';

	cout.precision(3); // 12.3
	cout << n << '\n';

	cout.precision(4);
	cout << n << '\n'; // 12.35 (�ݿø�)

	cout << fixed; // �Ҽ��� �ڸ��� ����
	cout.precision(1);
	cout << n << '\n'; // 12.3

	cout.precision(3);
	cout << n << '\n'; // 12.346 (�ݿø�)

	cout.precision(5);
	cout << n << '\n'; // 12.34567

	return 0;
}