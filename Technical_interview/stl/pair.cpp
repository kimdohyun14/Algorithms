#include <iostream>
#include <utility>
using namespace std;

// pair
// 2���� �����͸� ������ �� �ִ� �����̴�.
// �� ����� 1���� first, 2���� second�� �Ǻ��Ѵ�.

int main()
{
	// int, int �ڷ����� �����ϴ� ���� ����
	pair<int, int> p;
	// (4,5)�� ����
	p = make_pair(4, 5);
	cout << p.first << ' ' << p.second << '\n';
	// c++11���� ����
	p = { 5, 6 };
	// ���
	cout << p.first << ' ' << p.second << '\n';
	return 0;
}