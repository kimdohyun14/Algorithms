#include <iostream>
using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;

	// ������ ������ ����������, �������� �������� �ʴ´�.
	cout << (a + b) % c << '\n';
	cout << ((a % c) + (b % c)) % c << '\n';
	
	cout << (a * b) % c << '\n';
	cout << ((a % c) * (b % c)) % c << '\n';

	/* ������ ���� �Ʒ��� ���� */
	// (a - b) % c = (( a % c ) - ( b % c ) + c ) % c
	return 0;
}