#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	// ť�� ���� O(1)
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	// ť�� ���� O(1)
	q.pop();

	// ť�� ũ�� O(1)
	cout << "q.size(): " << q.size() << '\n';
	// ť�� ��, �� Ȯ�� O(1)
	cout << "q.front(): " << q.front() << '\n';
	cout << "q.back(): " << q.back() << '\n';

	// ���� ���� ���Һ��� ����
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}