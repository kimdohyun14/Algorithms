#include <iostream>
using namespace std;

// less�� < �������� �Լ� ��ü
// greater > �������� �Լ� ��ü

bool Pred_less(int a, int b)
{
	return a < b;
}

// Less ����
struct Less
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	Less l;

	cout << Pred_less(10, 20) << endl;
	cout << Pred_less(20, 10) << endl;
	cout << endl;

	cout << l(10, 20) << endl; // ��ü�� �Ϲ��� �Լ� ȣ��
	cout << l(20, 10) << endl;

	cout << Less()(10, 20) << endl; // �ӽ� ��ü�� �Ϲ��� �Լ� ȣ��
	cout << Less()(20, 10) << endl;
	cout << endl;

	cout << l.operator()(10, 20) << endl; // ����� ȣ��
	cout << l.operator()(20, 10) << endl;

	return 0;
}