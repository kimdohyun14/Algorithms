#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

void input()
{
	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
}

bool calc(int mid)
{
	int cnt = 1; // �������� ����
	int cur = v[0];
	for (int i = 1; i < n; i++)
	{
		// ������ ������ ���� ������ �Ÿ��� ����ϴٸ� ī��Ʈ
		if (v[i] - cur >= mid)
		{
			cnt++;
			cur = v[i];
		}
	}

	// �������� ������ ���̷��� ������ ������. (������ �ִٴ� �ǹ�)
	if (cnt >= c) return true;
	else return false;
}

void solve()
{
	input();
	sort(v.begin(), v.end());

	long long left = 0, right = 1e9;
	int answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (calc(mid))
		{
			answer = mid;
			left = mid + 1;
		}
		else // �������� ������ �ø����� ������ ������ �Ÿ��� �������Ѵ�.
			right = mid - 1;
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}