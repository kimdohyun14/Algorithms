#include <iostream>
using namespace std;

// pivot�� ���� ������ ������ �ΰ� �����Ѵ�.
// https://blog.naver.com/ndb796/221226813382 (����)
void quickSort(int* data, int start, int end) {
	if (start >= end) { // ���Ұ� 1���� ���
		return;
	}

	int pivot = start;  // pivot
	int i = start + 1;
	int j = end;
	int temp;

	// ������ ������ �ݺ�
	while (i <= j) {
		// pivot ������ ū ���� ���� ������ �ݺ�
		while (data[i] <= data[pivot])
			i++;
		// pivot ������ ���� ���� ���� ������ �ݺ�
		while (data[j] >= data[pivot] && j > start)
			j--;
		if (i > j) { // ���� ������ ���¸�
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	// pivot�� �ε����� j�� ���ĵǾ������Ƿ�
	// j�� �������� ���ʰ� �������� �ٽ� �����ؼ� ��������.
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	int number = 10;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	
	quickSort(arr, 0, number - 1);
	for (int i = 0; i < number; i++)
		cout << arr[i] << ' ';
	return 0;
}