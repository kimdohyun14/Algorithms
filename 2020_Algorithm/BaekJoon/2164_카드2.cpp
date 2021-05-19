#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	// ���ʿ� ī�尡 1���̸� ������ 1
	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	int kard = 0;
	while (1)
	{
		// ���� ���� �ִ� ī�带 ����. (ī�尡 �� �� ������ ��)
		if (!q.empty()) q.pop();
		if (q.size() == 1) break;
		// ���� ���� �ִ� ī�带 ���� �������� �ִ´�.
		kard = q.front();
		q.pop();
		q.push(kard);
	}

	cout << q.front();
	return 0;
}