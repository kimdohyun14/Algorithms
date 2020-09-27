#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
	// ������ ���� O(1)
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	// ������ �ֻ�� ���� Ȯ�� O(1)
	cout << "top: " << s.top() << '\n';
	// ������ ��������� 1, �ƴϸ� 0, O(1)
	cout << "stack.empty(): " << s.empty() << '\n';
	// ���ÿ� ����ִ� ������ ���� O(1)
	cout << "stack.size(): " << s.size() << '\n';
	
	// ������ ���� O(1)
	s.pop();

	// ������ �ֻ�� ���Һ��� ���
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}