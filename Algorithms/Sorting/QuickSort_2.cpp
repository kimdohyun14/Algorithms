#include <iostream>
using namespace std;

// pivot�� ���� �ڸ� ������ �ΰ� �����Ѵ�.

void swap(int* data, int a, int b) {
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

// pivot�� � �������� �������� ���ϴ� �Լ�
int partition(int* data, int p, int r) {

	int pivot = data[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++) {
		if (data[j] <= pivot) {
			i++;
			swap(data, i, j);
		}
	}
	swap(data, i + 1, r);
	return i + 1;
}

// p�� ù��° ����, r�� ������ ���Ҹ� ����Ŵ
void quickSort(int* data, int p, int r) {
	int q;
	if (p < r) {
		q = partition(data, p, r);
		quickSort(data, p, q - 1);
		quickSort(data, q + 1, r);
	}
	else { // Ż�� ����
		return;
	}
}

void printSorted(int* data, int size) {
	cout << "���ĵ� �迭 : ";
	for (int i = 0; i < size; i++)
		cout << data[i] << ' ';
	cout << endl;
}

int main() {
	int number = 10;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	quickSort(arr, 0, number - 1);
	printSorted(arr, number);
	return 0;
}