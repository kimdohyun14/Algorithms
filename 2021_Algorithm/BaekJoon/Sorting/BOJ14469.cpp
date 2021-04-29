#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int ans = v[0].first + v[0].second;
	for (int i = 1; i < v.size(); i++)
	{
		// ��ٸ� �ð��� ������ �����ð� + �˹��ð�
		if (ans <= v[i].first)
		{
			ans = v[i].first + v[i].second;
		}
		// ��ٸ� �ð��� �ִٸ� ����� �ð� + �˹��ð�
		else
		{
			ans = ans + v[i].second;
		}
	}

	cout << ans << '\n';
	return 0;
}