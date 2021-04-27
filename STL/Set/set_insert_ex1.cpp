#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s; // less <
	// left node < parent node < right node

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter; // set�� ����� �ݺ��� (���ʵ� �� �� �ְ�, �����ʵ� �� �� �ְ�)
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	s.insert(50); // �ߺ��� ���Ҹ� ���������� ����.

	auto p = s.insert(50); // pair<iter, boo> Ÿ��
	if (p.second)
		cout << "50 ���� ����!\n";
	else
		cout << "50 ���� ����!\n";
	
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';
	return 0;
}