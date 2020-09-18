#include <bits/stdc++.h>
using namespace std;

// ���� Ž�� �ҽ��ڵ� ����(�ݺ���)
int BinarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		// ã�� ��� �߰��� �ε��� ��ȯ
		if (arr[mid] == target) return mid;
		// �߰����� ������ ã���� �ϴ� ���� ���� ��� ���� Ȯ��
		else if (arr[mid] > target) end = mid - 1;
		// �߰����� ������ ã���� �ϴ� ���� ū ��� ������ Ȯ��
		else start = mid + 1;
	}
	return -1;
}

int n, m;
// ���Կ� �ִ� ��ü ��ǰ ��ȣ��
vector<int> arr;
// �մ��� Ȯ�� ��û�� ��ǰ ��ȣ��
vector<int> targets;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// ���� Ž���� �����ϱ� ���� ������ ���� ����
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		targets.push_back(target);
	}

	// �մ��� Ȯ�� ��û�� ��ǰ ��ȣ�� �ϳ��� Ȯ��
	for (int i = 0; i < m; i++) {
		// �ش� ��ǰ�� �����ϴ��� Ȯ��
		int result = BinarySearch(arr, targets[i], 0, n - 1);
		if (result != -1)
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}

	return 0;
}