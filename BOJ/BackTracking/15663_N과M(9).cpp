#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a[9];
int b[9];
bool check[9];

void solve(int index)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	// �ߺ��Ǵ� ������ ������ �ش� ���ڰ� ������� üũ
	bool used[10001] = { false };
	for (int i = 0; i < n; i++)
	{
		if (used[b[i]] == false)
		{
			if (check[i] == false)
			{
				used[b[i]] = true;
				a[index] = b[i];
				check[i] = true;
				solve(index + 1);
				check[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(b, b + n);
	solve(0);
	return 0;
}