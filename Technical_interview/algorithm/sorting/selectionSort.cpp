#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int idx = i;
		// �ּڰ��� ���� �ε��� ã��
		for (int j = i + 1; j < v.size(); j++) {
			if (v[idx] > v[j]) {
				idx = j;
			}
		}
		// �ּڰ� �ε����� �ڱ� �ڽ��̸� �������� �ʴ´�.
		if (i != idx) {
			swap(v[i], v[idx]);
		}
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	selectionSort(v);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}