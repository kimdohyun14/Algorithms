#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int binarySearch(int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	// �������� ã�� ��� �߰��� �ε��� ��ȯ
	if (v[mid] == mid) return mid;
	// �߰����� ������ �߰����� ���� ��� ���� Ȯ��
	else if (v[mid] > mid) return binarySearch(start, mid - 1);
	// �߰����� ������ �߰����� ū ��� ������ Ȯ��
	else return binarySearch(mid + 1, end);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int index = binarySearch(0, n - 1);
	cout << index << '\n';
	return 0;
}