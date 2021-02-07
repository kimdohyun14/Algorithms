#include <iostream>
using namespace std;

/* �Լ� �����͸� �̿��� �ݹ� ��Ŀ���� ���� */

// �迭�� ��� ���ҿ� �ݺ����� �۾��� �����ϰ� �߻�ȭ��.(��ü���� �۾��� ����)
// ������ ���� Ŭ���̾�Ʈ�� ���� ȣ��Ǹ� Ŭ���̾�Ʈ�� ���縦 �� �� ����.
// ���� Ŭ���̾�Ʈ�� ������ ȣ���� �� ������ Ŭ���̾�Ʈ�� ������ �����ؾ� �Ѵ�.
// ���⼭�� �Լ� ������ �Ű������� �̿��� �ݹ� �Լ��� �ּҸ� �����ϴ� ����� �����ش�.
void For_each(int* begin, int* end, void(*pf)(int))
{
	while (begin != end)
	{
		pf(*begin++); // Ŭ���̾�Ʈ �Լ� ȣ��(�ݹ�)
	}
}

// Ŭ���̾�Ʈ
void Print1(int n)
{
	cout << n << ' ';
}

void Print2(int n)
{
	cout << n * n << ' ';
}

void Print3(int n)
{
	cout << "����: " << n << endl;
}

int main()
{
	int arr[5] = { 10,20,30,40,50 };

	For_each(arr, arr + 5, Print1); // Print1() �ݹ� �Լ��� �ּҸ� ����
	cout << endl << endl;

	For_each(arr, arr + 5, Print2);
	cout << endl << endl;

	For_each(arr, arr + 5, Print3);
	cout << endl << endl;

	return 0;
}