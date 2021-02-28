#include <iostream> 
#include <tuple> // std::tuple, std::get, std::tie, std::ignore
using namespace std;

/*
	#tuple�� ���Ե� ���
	�Լ��� ���� �� ��Ȥ 2�� �̻��� ���� �ѹ��� �����ϰ� ���� ���� �ִ�.
	�̷��� �������� ����ü�� �����ϰ� ����ü ������ �ϳ� ������ �� ���� �ְ� �����ؾ��ߴ�.
	���� ���ϰ��� ������ �ް� ���� ���ε� ����ü�� �����ؾ� �Ѵٴ� ���� �� �δ��� �ִ�.

	C++11������ �̷� �������� ���ֱ� ���� tuple�� �����ߴ�.
	tuple�� ����ϸ� 2�� �̻��� ������ �ѹ��� ��� ������ �� �ִ�.

	������ ���� 3���̻���� ����ϰ�, 2���� ���� pair�� ����.
*/

int main()
{
	tuple<int, char> foo(10, 'x');
	auto bar = make_tuple("test", 3.1, 14, 'y');

	get<2>(bar) = 100; // access element

	int myint; char mychar;

	tie(myint, mychar) = foo; // unpack elements, �̷��� �̾ƿ� �� �ִ�.
	cout << "myint : " << myint << endl;
	cout << "mychar : " << mychar << endl;

	tie(std::ignore, std::ignore, myint, mychar) = bar; // unpack with ignore, ignore�� �����Ѵ�.
	cout << "myint : " << myint << endl;
	cout << "mychar : " << mychar << endl;

	mychar = get<3>(bar);

	get<0>(foo) = get<2>(bar);
	get<1>(foo) = mychar;

	cout << "foo contains: ";
	cout << std::get<0>(foo) << ' ';
	cout << std::get<1>(foo) << '\n';

	return 0;
}