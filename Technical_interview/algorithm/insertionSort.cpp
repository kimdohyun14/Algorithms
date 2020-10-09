#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& v) {
	int key, j;
	// ù ��° �ε����� �̹� ���ĵǾ��ִٰ� �����Ѵ�.
	for (int i = 1; i < v.size(); i++) {
		key = v[i];

		// ������ ���� ã�´�.
		for (j = i - 1; j >= 0 && v[j] > key; j--) {
			v[j + 1] = v[j]; // ���������� �̵�
		}
		// ������ ���� ã�Ҵٸ� �װ��� �־��ش�.
		v[j + 1] = key;
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	insertionSort(v);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}