#include <iostream>
#include <functional> // less<>, greater<> ���
using namespace std;

struct Less
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct Greater
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	cout << Less()(10, 20) << endl; // ����� ���� Less, Greater ���
	cout << Less()(20, 10) << endl;
	cout << endl;

	cout << Greater()(10, 20) << endl;
	cout << Greater()(20, 10) << endl;
	cout << endl;

	cout << less<int>()(10, 20) << endl; // STL�� less, greater ���
	cout << less<int>()(20, 10) << endl;
	cout << greater<int>()(10, 20) << endl;
	cout << greater<int>()(20, 10) << endl;

	return 0;
}