#include <iostream>
#include <vector>
using namespace std;

// �� ���Ҹ� ���Խ�ų�� ������ �� �õ��غ���.

int ans;

void solve(vector<int>& v, int idx, int sum, int s)
{
	// ������ ���
	if (sum == s && idx == v.size())
	{
		ans++;
		return;
	}

	// �Ұ����� ���
	if (idx >= v.size()) return;

	// idx���� ���ڸ� �����ϴ� ���
	solve(v, idx + 1, sum + v[idx], s);
	// idx���� ���ڸ� �������� �ʴ� ���
	solve(v, idx + 1, sum, s);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, s;
	cin >> n >> s;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	solve(v, 0, 0, s);

	if (s == 0) cout << ans - 1;
	else cout << ans;
	return 0;
}