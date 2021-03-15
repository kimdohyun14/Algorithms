#include <iostream>
using namespace std;

/*
	# ���� ���� (Selection Sort)
	���� ���� �����͸� �����ؼ� ���ĵ��� ���� ������ �߿���
	���� ���ʿ� �ִ� �����Ϳ� ��ġ�� �ٲٴ� �˰���

	# �ð� ���⵵
	O(N^2)

	N-1�� ��ŭ ���� ���� ���� ã�Ƽ� �� ������ ������ �ϸ�,
	�Ź� ���� ���� ���� ã�� ���ؼ� �� ������ �ʿ��ϴ�.
*/

int n = 10;
int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

int main()
{
	for (int i = 0; i < n; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}
		swap(arr[i], arr[minIdx]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}