#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;

void input()
{
	cin >> n >> k;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
}

void solve()
{
	input();

	// �� ������ �˰���
	int sum = 0, ans = 0;
	for (int left = 0, right = 0; left < n; left++)
	{
		// right�� ������ ��ŭ �̵���Ű��
		while (sum < k && right < n)
		{
			sum += v[right];
			right++;
		}

		// �κ� ���� k�� ��, ī��Ʈ
		if (sum == k) ans++;

		sum -= v[left];
	}

	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}