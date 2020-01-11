#include <iostream>
#include <vector>
using namespace std;

int ans;

void solve(vector<int>& v, int index, int sum, int goal)
{
	// ������ ���
	if (sum == goal && index == v.size())
	{
		ans++;
		return;
	}
	// �Ұ����� ���
	if (index >= v.size())
		return;
	// ���� ���
	solve(v, index + 1, sum + v[index], goal);
	solve(v, index + 1, sum, goal);
}

int main()
{
	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	solve(v, 0, 0, s);

	if (s == 0) // ���� 0�̶��, �������� �����ؾ� �Ѵ�.
		cout << ans - 1;
	else
		cout << ans;

	return 0;
}