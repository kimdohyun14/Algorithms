#include <iostream>
#include <stack>
using namespace std;

int N, P;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> P;
	stack<int> st[7];
	int ans = 0;

	while (N--)
	{
		int n, p;
		// ���� �Ƿ�
		cin >> n >> p;

		if (st[n].empty())
		{
			ans++;
			st[n].push(p);
			continue;
		}

		if (st[n].top() < p)
		{
			ans++;
			st[n].push(p);
		}
		// �̹� ������������
		else if (st[n].top() == p)
			continue;
		else
		{
			while (!st[n].empty() && st[n].top() > p)
			{
				ans++;
				st[n].pop();
			}

			// �̹� ������������
			if (!st[n].empty() && st[n].top() == p) continue;
			ans++;
			st[n].push(p);
		}
	}

	cout << ans;
	return 0;
}