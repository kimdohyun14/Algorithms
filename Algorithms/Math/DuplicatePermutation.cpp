// https://yabmoons.tistory.com/123

/* �ߺ�����
   
   ������ ������ ������ �����ϴ� �����̸�, �� ������ �߿��ϴ�.
   ���ÿ� {1,2} != {2,1}�� �ٸ��� ������ �Ѵ� �����ش�.

   ���⼭ �ߺ��� ���Ǿ��ٴ� ���� �߰��� ���� �ߺ� �����̴�.

   {1,2,3}���� 2���� ���� ��
   {1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}
   
   ���״�� �ߺ��� ���� ���� �ߺ������̴�.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = { 1,2,3,4,5 };
vector<int> select(5);

void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << select[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		select[cnt] = arr[i];
		DFS(cnt + 1);
	}
}

int main()
{
	DFS(0);
	return 0;
}