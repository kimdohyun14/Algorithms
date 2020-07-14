// https://yabmoons.tistory.com/122

// �ߺ� ����

/*
	�ߺ� ����: ���տ��� �ߺ��� ����Ѵ�.

	{1,2,3}���� 2���� �̴´ٸ�
	{1,1}{1,2}{1,3}{2,2}{2,3}{3,3}

									   DFS(0,0)
	     
			 DFS(0,1)                  DFS(1,1)               DFS(2,1)
	DFS(0,2) DFS(1,2)  DFS(2,2)     DFS(1,2) DFS(2,2)         DFS(2,2)
      {1,1}   {1,2}      {1,3}        {2,2}   {2,3}            {3,3}

	�ٽ��� ��ͷ� ������ ������ ������ �������� ������ ����, �� ���� ��Ҵ� �ٽô� �Ĵٵ� �Ⱥ��ٴ� ���� �߿��ϴ�.
*/

#include <iostream>

#define MAX 3
using namespace std;

int arr[MAX];
int select[MAX];

void DFS(int index, int cnt)
{
	//cout << "DFS(" << index << "," << cnt << ")" << endl;
	if (cnt == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << select[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = index; i < MAX; i++)
	{
		select[cnt] = arr[i]; // cnt��° ���� ī��� arr[i]�Դϴ�.
		DFS(i, cnt + 1);
	}
}

int main()
{
	for (int i = 0; i < MAX; i++) arr[i] = i + 1;
	DFS(0, 0);
	return 0;
}