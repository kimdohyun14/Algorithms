/* �Լ� ��ü�� ������ sort �˰���

   �Լ� ��ü�� ����ϸ� STL ���� ��Ҹ� ���� �����ϰ� ����� �� �ִ�.
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);

	// sort(b,e,f) f�� ���� �������� �����Ѵ�.

	sort(v.begin(), v.end(), less<int>()); // �������� ����
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	sort(v.begin(), v.end(), greater<int>()); // �������� ����
	for (int n : v)
		cout << n << ' ';
	cout << endl;

	return 0;
}