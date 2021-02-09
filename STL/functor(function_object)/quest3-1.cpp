#include <iostream>
using namespace std;

class Equal
{
public:
	bool operator()(int a, int b) const
	{
		return a == b;
	}
};

class Adder
{
public:
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	Equal cmp;
	Adder add;

	if (cmp(10, 20))
		cout << "����!" << endl;
	else
		cout << "�ٸ���!" << endl;

	int sum = add(10, 20);
	cout << "sum= " << sum << endl;

	return 0;
}