#include <iostream>
using namespace std;

// �Լ� ��ü ���� (�ٸ� ���� Functor��� �θ�)

void Print()
{
	cout << "���� �Լ�!" << endl;
}

struct Functor
{
	void operator()()
	{
		cout << "�Լ� ��ü!" << endl;
	}
};

int main()
{
	Functor functor;

	Print(); // ���� �Լ� ȣ��
	functor(); // ��� �Լ� ȣ�� functor.operator()�� ����

	return 0;
}