#include <iostream>
using namespace std;

/*
	# �� ���� (Quick Sort)
	���� �����͸� �����ϰ� �� ���غ��� ū �����Ϳ� ���� �������� ��ġ�� �ٲٴ� �˰���
	������ ���⼭ pivot �̶�� �Ѵ�.

	1. ����Ʈ���� ù ��° �����͸� pivot���� ���Ѵ�.
	2. ���ʿ������� pivot���� ū �����͸� ã��, �����ʿ������� pivot���� ���� �����͸� ã�´�.
	3. ū �����Ϳ� ���� �������� ��ġ�� swap�Ѵ�.

	# �ð� ���⵵
	best, average : O(NlogN)
	�������� ���� N * ���� logN = NlogN

	Worst : O(N^2), �־��� ����Ʈ�� �̹� ���ĵ� ���¶�� �ſ� ������ �����Ѵ�.
	�̴� �������� ����� ������ �����ֱ� �����̴�.
	�������� ���� N * ���� N = N^2
*/

int n = 10;
int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

void quickSort(int arr[], int start, int end)
{
	if (start >= end) return; // �������� ������ ������ 1���� ��
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right)
	{
		// ������ pivot���� ū �����͸� ã�� ������ �ݺ�
		while (left <= end && arr[left] <= arr[pivot]) left++;
		// �������� pivot���� ���� �����͸� ã�� ������ �ݺ�
		while (right > start && arr[right] >= arr[pivot]) right--;
		// �����ȴٸ� ���� �����Ϳ� pivot�� ����
		if (left > right) swap(arr[pivot], arr[right]);
		// �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ����
		else swap(arr[left], arr[right]);
	}

	// ���� ���� ���� �κа� ������ �κп��� ���� �� ������ �ٽ� ����
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}

int main()
{
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	
	return 0;
}