/* �Լ� ���ø� 

   �Լ� ȣ�� ���� Ÿ���� ���� ���ø� �Լ��� �Ű����� Ÿ���� �����Ѵ�.
   ��, Ÿ���� �ٸ� �Լ��� �󸶵��� �����Ƿ� Ȯ�强�� ������.

   �������� �Ϸ�Ǹ� �Լ� ���ø��� �������� ������
   �ν��Ͻ�ȭ�� �� �Լ��� �ִ�.
   ���⼭ ���ϴ� �� �Լ���
   Print<int>(), Print<double>(), Print<const char*>()
*/
#include <iostream>
using namespace std;

template<typename T>
void Print(T a, T b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	// �Ͻ������� �����Ϸ��� Ÿ���� ���� ������.
	Print(10, 20);
	Print(0.123, 1.123);
	Print("ABC", "abcde");

	// ��������� Ŭ���̾�Ʈ�� ���� �����Ͽ� ȣ����.
	Print<int>(10, 20);
	Print<double>(0.123, 1.123);
	Print<const char*>("ABC", "abcde");

	return 0;
}