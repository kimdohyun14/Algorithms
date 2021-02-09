/* �Լ� ���ø� For_each() */
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) // �Լ� ���ø�
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

template<typename T>
void Print(T data) // �Լ� ���ø�
{
	cout << data << " ";
}

int main()
{
	int arr[5] = { 10,20,30,40,50 };
	For_each(arr, arr + 5, Print<int>); // Print<int>�� ��������� ����� �Ѵ�. ������ �� �����Ƿ�
	cout << endl;

	string sarr[3] = { "abc","ABCDE","Hello!" };
	For_each(sarr, sarr + 3, Print<string>);
	cout << endl;

	// ��������� ȣ��
	For_each<int*, void(*)(int)>(arr, arr + 5, Print<int>);
	cout << endl;

	For_each<string*, void(*)(string)>(sarr, sarr + 3, Print<string>);
	cout << endl;

	return 0;
}