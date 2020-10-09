#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int left, int right, int mid) {
	vector<int> tmp; // �߰����� �迭�� �ʿ��ϴ�.
	int i = left;
	int j = mid + 1;
	int cnt = 0;
	// ���� ���ĵ� list�� �պ��Ѵ�.
	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			tmp.push_back(v[i++]);
		}
		else {
			tmp.push_back(v[j++]);
		}
	}

	// �����ִ� ������ �ڿ� ä���.
	while (i <= mid) {
		tmp.push_back(v[i++]);
	}
	while (j <= right) {
		tmp.push_back(v[j++]);
	}

	// ���� �迭�� �����Ѵ�.
	for (int k = left; k <= right; k++) {
		v[k] = tmp[cnt++];
	}
}

void mergeSort(vector<int>& v, int start, int end) {
	// ���� ũ�Ⱑ 1�����̶�� left == right�̹Ƿ� Ż��
	// �̴� ���ĵǾ��ٴ� ���� �ǹ��Ѵ�.
	// �ƴ϶�� ����ؼ� ������ �ɰ� �����Ѵ�.
	if (start < end) {
		int mid = (start + end) / 2; // �յ�(divide)
		mergeSort(v, start, mid);    // ���� �κ� �迭 ����(conquer)
		mergeSort(v, mid + 1, end);  // ���� �κ� �迭 ����(conquer)
		merge(v, start, end, mid);   // ���ĵ� 2���� �κ� �迭�� �����ϴ� ����(combine)
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	mergeSort(v, 0, v.size() - 1);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}