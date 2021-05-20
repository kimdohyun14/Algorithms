#include <iostream>
#include <cmath>
using namespace std;

int n, ans;
int col[15]; // col[i] = j : (i,j)�� Queen�� ��ġ

bool isPromising(int row)
{
	// [0 ~ row) �ܰ� ���� ��, �밢�� üũ
	for (int i = 0; i < row; i++)
	{
		if (col[i] == col[row]) return false;
		if (abs(i - row) == abs(col[i] - col[row])) return false;
	}

	return true;
}

// row�� ������ ���� ���� ����,
void dfs(int row)
{
	if (row == n)
	{
		ans++;
		return;
	}
	// row+1�࿡ ���� ���� �� �ִ��� ������ Ȯ�� (��������?)
	for (int i = 0; i < n; i++)
	{
		col[row] = i;
		if (isPromising(row))
			dfs(row + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dfs(0);
	cout << ans << '\n';
	return 0;
}