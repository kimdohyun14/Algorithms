#include <iostream>
using namespace std;

int number = 8;
int sorted[8]; // �߰����� �޸� ������ �ʿ�

// ��ġ�� ������ ������ �����Ѵ�.
void merge(int* arr, int first, int mid, int end) {
	int i = first;
	int j = mid + 1;
	int k = first;
	// ���� ������� �迭�� ����
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	// ���� �����͵� ������� ����
	if (i > mid) { // right �迭�� �����Ͱ� �����ִ� ���
		for (int t = j; t <= end; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else { // left �迭�� �����Ͱ� �����ִ� ���
		for (int t = i; t <= mid; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	// ���ĵ� �迭�� ���� �迭�� �����Ѵ�.
	for (int t = first; t <= end; t++) {
		arr[t] = sorted[t];
	}
}

void mergeSort(int* arr, int first, int end) {
	// ũ�Ⱑ 1���� ū ���
	if (first < end) {
		int mid = (first + end) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, first, mid, end);
	}
}

int main() {
	int array[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		cout << array[i] << ' ';
	}
	return 0;
}