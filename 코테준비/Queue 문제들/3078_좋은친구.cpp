// https://blog.junu.dev/30

// queue�� ���� �� ���� ����ؼ� Ǯ������������, ���� ���� �̿��ϴ� �͵� �����غ���.
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	queue<int> q[21];
	vector<string> v;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	long ans = 0;
	for(int i = 0; i < n; i++)
	{
		string now = v[i];
		int idx = now.length();

		if (q[idx].empty())
			q[idx].push(i);
		else
		{
			// ���� ģ�� ������ �������� ���ϸ�, ����
			while (i - q[idx].front() > k)
			{
				q[idx].pop();
				if (q[idx].empty()) break;
			}
				

			ans += q[idx].size();
			q[idx].push(i);
		}
	}

	cout << ans;
	return 0;
}