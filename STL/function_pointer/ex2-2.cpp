#include <iostream>
using namespace std;

/* �Լ� ������ ����� ��� */

void Print(int n)
{
	cout << "����: " << n << endl;
}

int main()
{
	void (*pf)(int);
	pf = Print; // �Լ��� �̸��� �Լ��� ���� �ּ�

	Print(10); // 1. �Լ� ȣ��
	pf(10);    // 2. �����͸� �̿��� �Լ� ȣ��
	(*pf)(10); // 3. �����͸� �̿��� �Լ� ȣ��

	cout << endl;
	cout << Print << endl;
	cout << pf << endl;
	cout << *pf << endl;
	return 0;
}