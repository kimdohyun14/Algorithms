#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int start, int end) {
	// pivot�� ���� �������� ��� ���
	int pivot = v[start];
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (v[left] <= pivot) left++;
		while (v[right] > pivot) right--;
		// left�� right�� �������� �ʾҴٸ� ����
		if (left <= right) {
			swap(v[left], v[right]);
		}
	}

	// ������ pivot ��ġ�� right ��ġ�� �ٲ��ش�.
	// pivot�� �������� ������ pivot���� ���� �͵���
	// �������� pivot���� ū �͵��� ��ġ�ϰ� �ǹǷ�
	// pivot�� ����Ű�� ���� right�� ����Ű�� ���� �ٲ���� �Ѵ�.
	swap(v[start], v[right]);
	return right;
}

void quickSort(vector<int>& v, int start, int end) {
	if (start < end) {
		int pivot = partition(v, start, end);
		quickSort(v, start, pivot - 1);
		quickSort(v, pivot + 1, end);
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	quickSort(v, 0, v.size() - 1);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}