// https://yabmoons.tistory.com/122

/* �ߺ�����

   ���տ��� �ߺ��� ����ϴ� ���� �ߺ� �����̴�.

   {1,2,3}���� 2���� �̴´ٸ�
   {1,1},{1,2},{1,3},{2,2},{2,3},{3,3}

   {1,2,3}���� 3���� �̴´ٸ�
   {1,1,1},{1,1,2},{1,1,3},{1,2,2},{1,2,3},{1,3,3}
   {2,2,2},{2,2,3},{2,3,3},{3,3,3}

   �ٽ��� ��ͷ� ������ ������ �� �������� ������ ����,
   �� ���� ��Ҵ� �ٽô� �Ĵٵ� �� ���ٴ� ���� �߿��ϴ�.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = { 1,2,3 };
vector<int> select(3);

void DFS(int index, int cnt)
{
	if (cnt == 2)
	{
		for (int i = 0; i < 2; ++i)
			cout << select[i] << " ";
		cout << endl;
		return;
	}

	for (int i = index; i < 3; ++i)
	{
		select[cnt] = arr[i]; // cnt��° ���� ī��� arr[i]
		DFS(i, cnt + 1);
	}
}

int main()
{
	DFS(0, 0);
	return 0;
}