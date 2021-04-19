#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// �Է��� 10^6�̶� O(N)�� �ذ��ؾ���.
int n;
vector<int> v;
deque<int> dq;

// �������� An�� �׻� 1�̶� ������ ��ų���� ����Ϸ��� �ϸ� ī�尡 2���̻� �Ǿ��Ѵ�.
// ���� �Է��� 2 3 3 2 1�� �־�����
// �츮�� �Ųٷ� �Ž����ö󰡸鼭 Ǯ��� �ذ��� �� �ִ�.

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int card = 1;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 1)
			dq.push_back(card++);
		else if (v[i] == 2)
		{
			int memo = dq.back();
			dq.pop_back();
			dq.push_back(card++);
			dq.push_back(memo);
		}
		else
			dq.push_front(card++);
	}

	while (!dq.empty())
	{
		cout << dq.back() << ' ';
		dq.pop_back();
	}

	return 0;
}