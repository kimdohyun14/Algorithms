#include <iostream>
using namespace std;

void swap(int* arr, int p1, int p2) {
	int temp = arr[p1];
	arr[p1] = arr[p2];
	arr[p2] = temp;
}

bool next_permutation(int * arr, int n) {
	int i = n - 1;
	while (i > 0 && arr[i - 1] >= arr[i])
		i -= 1;
	if (i <= 0) return false; //�� ������ ������ ����
	int j = n - 1;
	while (arr[j] <= arr[i - 1])
		j -= 1;
	swap(arr, i - 1, j);
	//���� ������
	j = n - 1;
	while (i < j) {
		swap(arr, i, j);
		++i;
		--j;
	}
	return true; //���� ������ ����.
}

int main() {
	int arr[9] = { 1,2,3,4,5,6,7,8 };
	int n;
	scanf("%d", &n);
	do { //ù ������ �״�� ��´�.
		for (int i = 0; i < n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} while (next_permutation(arr, n)); //���� ������ �ִٸ� loop�� ���� �ƴ϶�� �����Ѵ�.
	return 0;
}