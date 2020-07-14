// https://yabmoons.tistory.com/123

// �ߺ� ����

/*
	�����̶�� ���� ������ �����ϴ� �����̸�,
	���ÿ� {1,2} != {2,1}�� �ٸ� ����̴�. (������ �ſ� �߿�)

	���⼭ �ߺ��� ���Ǿ��ٴ� ���� �߰��� ���� �ߺ� ����

	{1,2,3}���� 2���� ���� ��
	{1,1}{1,2}{1,3}{2,1}{2,2}{2,3}{3,1}{3,2}{3,3}
*/

#include <iostream>

#define MAX 5
using namespace std;

int arr[MAX];
int select[MAX];

// ���������� index�� �ʿ䰡 �����Ƿ�, cnt�� ����Ѵ�.
void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << select[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		select[cnt] = arr[i];
		DFS(cnt + 1);
	}
}

int main()
{
	for (int i = 0; i < MAX; i++) arr[i] = i + 1;
	DFS(0);
	return 0;
}