#include <iostream>
using namespace std;

int n = 10;
int arr[1000001];

void quickSort(int st, int en)
{
	if (en <= st + 1) return; // base condition : ������ ���̰� 1������ ��

	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;
	
	while (1)
	{
		while (l <= r && arr[l] <= pivot) l++;
		while (l <= r && arr[r] >= pivot) r--;
		if (l > r) break; // ������ ����
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);
	quickSort(st, r);
	quickSort(r + 1, en);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	quickSort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	return 0;
}