// https://yabmoons.tistory.com/100

// ������ ���ؼ�

/* �����̶�?
   
   ������ �����ϴ� ���̴�.
   {1,2,3}�� {1,3,2}�� ����� �ٸ��ٴ� ��.(������ �ٸ��Ƿ�)

   C++ STL���� next_permutation / prev_permutation�� ���ؼ� ���� ��� ����.
   �ٸ�, ��������� ¥�� �ڵ��� ������ �߿��ϴ�.

   ���������� 5�� �߿��� 3���� �̴´ٰ� �ϸ�?
   {1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5} ... {1,4,5} ...
   {2,1,3},{2,1,4},{2,1,5} ...
   ...

   {1,2,3} != {2,1,3} �� �ٽ�

   �ش� �������� ���� ������ ���� ������ �ð� ���⵵�� O(N)�̴�.
   �ٸ�, ��ü ������ ���Ϸ��� �Ѵٸ� O(N!)�� �ɸ���.
   10! = 3,628,800  (3�鸸)
   11! = 39,916,800 (4õ)
   12! = 479,001,600(4��)

   �˰����� ����Ϸ��� �ִ��� 10 ~ 11�� ���� �ʴ� �������� �����ϴ�.
   �Ѿ�� �ð� �ʰ�
*/

#include <iostream>
#include <vector>
using namespace std;

bool select[5];
vector<int> v;
vector<int> arr;

void DFS(int cnt)
{
	// 3���� �̾Ҵٸ�
	if (cnt == 3)
	{
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < 5; ++i)
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
	arr = { 1,2,3,4,5 };
	DFS(0);
	return 0;
}