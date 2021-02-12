// ������ �ݺ��� reverse_iterator
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	// �Ϲ� �ݺ��� iterator�� ������ �ݺ��� reverse_iterator�� ��ȯ
	reverse_iterator<vector<int>::iterator> riter(v.end());
	reverse_iterator<vector<int>::iterator> end_riter(v.begin());
	for (; riter != end_riter; ++riter)
		cout << *riter << ' ';
	cout << endl;

	// STL ��� �����̳ʴ� �ݺ��� ����� reverse_iterator�� typedef Ÿ������ �����Ͽ�
	// rbegin(), rend() �� �����̳��� ������ �ݺ��ڸ� ��ȯ
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	return 0;
}