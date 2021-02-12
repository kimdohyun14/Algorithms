/* sort �˰����� ���� ���� �ݺ��ڸ� �䱸�ϹǷ� vector, deque
   �� sort �˰����� ����������, �ٸ� �����̳ʴ� �Ұ����ϴ�.

   ���� �����̳ʴ� �����̳ʸ��� ���� ������ ������ �ִ�.
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	list<int> lt;
	lt.push_back(50);
	lt.push_back(40);
	lt.push_back(30);
	lt.push_back(20);
	lt.push_back(10);

	sort(v.begin(), v.end()); // ���� ���� (vector�� ���� ���� �ݺ���)
	//sort(lt.begin(), lt.end()); // ����! list�� ����� �ݺ���

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;

	return 0;
}