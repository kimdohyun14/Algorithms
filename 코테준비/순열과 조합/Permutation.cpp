// https://yabmoons.tistory.com/100

// ������ ���ؼ� ����

/* �����̶�?

	�� �״��, ������ �����ϴ� ���̴�.
	{1, 2, 3} �� {1, 3, 2}�� ����� �ٸ��ٴ� ��!

	C++ STL���� next_permutation / prev_permutation�� ���ؼ� ���� ������ ����.

	������, ��������� ¥�� �ڵ嵵 �߿��ϴٰ� �����ȴ�.

	���������� 5���߿��� 3���� �̴´ٰ� �ϸ�?
	{1,2,3} {1,2,4} {1,2,5} {1,3,4} {1,3,5} ... {1,4,5}...
	{2,1,3} {2,1,4} {2,1,5} {2,3,4} {2,3,5} {2,4,5}...
	...

    {1,2,3} != {2,1,3} �� �ٽ�
*/

#include <iostream>
#include <vector>
using namespace std;

int arr[5];
bool select[5];
vector<int> v;

void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		if (select[i] == true) continue;
		select[i] = true;
		v.push_back(arr[i]);
		DFS(cnt + 1);
		v.pop_back();
		select[i] = false;
	}
}

int main()
{
	for (int i = 0; i < 5; i++) arr[i] = i + 1;
	DFS(0);
	return 0;
}