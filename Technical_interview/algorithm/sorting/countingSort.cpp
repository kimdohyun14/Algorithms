#include <bits/stdc++.h>
using namespace std;

int bucket[100];

vector<int> countingSort(vector<int>& v) {
	vector<int> result(v.size());
	// �����ϴ� ���Ҹ� ����
	for (int i = 0; i < v.size(); i++) {
		bucket[v[i]]++;
	}
	// ������ ���
	for (int i = 1; i < v.size(); i++) {
		bucket[i] += bucket[i - 1];
	}
	// �������� �̿��� ����
	for (int i = 0; i < v.size(); i++) {
		bucket[v[i]]--;
		result[bucket[v[i]]] = v[i];
	}
	return result;
}

int main() {
	vector<int> arr = { 3,2,3,1,1 };
	vector<int> result = countingSort(arr);
	for (auto n : result) {
		cout << n << ' ';
	}
	return 0;
}