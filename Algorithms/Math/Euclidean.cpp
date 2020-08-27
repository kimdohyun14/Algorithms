#include <iostream>
using namespace std;

// ��Ŭ���� ȣ����
// �ִ� ������� ���ϴ� �˰���
// �ð� ���⵵ O(logN)

// ���
int recursive(int a, int b)
{
	if (b == 0) return a;
	else return recursive(b, a % b);
}

// �ݺ���
int loop(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	cout << recursive(12, 8) << endl;
	cout << recursive(8, 12) << endl;
	cout << loop(12, 8) << endl;
	cout << loop(8, 12) << endl;

	cout << recursive(120, 45) << endl;
	cout << recursive(45, 120) << endl;
	cout << loop(120, 45) << endl;
	cout << loop(45, 120) << endl;
	return 0;
}