#include <iostream>
#include <deque>
using namespace std;

// deque
// �����迭�̴�.
// ���Ϳ� ���������� ������ ��ġ�� ���� ���ٰ�
// �հ� �ڿ��� ���Ҹ� �߰��ϴ� ������ O(1)�� �����Ѵ�.

int main()
{
	// int�� �����ϴ� �����迭 ����
	deque<int> dq;
	// �迭�� �� �տ� ���� 5 �߰�
	dq.push_front(5);
	// �迭 �� �ڿ� ���� 5 �߰�
	dq.push_back(5);
	// �迭 �� ���� ���� ����
	dq.pop_front();
	// �迭 �� ���� ���� ����
	dq.pop_back();

	// ũ��
	cout << dq.size() << '\n';
	// ��������� 1 �ƴϸ� 0
	cout << dq.empty() << '\n';
	return 0;
}