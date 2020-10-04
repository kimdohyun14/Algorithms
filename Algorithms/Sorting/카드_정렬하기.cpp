#include <bits/stdc++.h>
using namespace std;

int n, result;
priority_queue<int> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}

	while (pq.size() != 1) {
		// ���� ���� 2���� ī�� ���� ������
		int one = -pq.top();
		pq.pop();
		int two = -pq.top();
		pq.pop();
		// ī�� ������ ���ļ� �ٽ� ����
		int summary = one + two;
		result += summary;
		pq.push(-summary);
	}

	cout << result << '\n';
	return 0;
}