#include <iostream>
#include <string>
using namespace std;

// ���� ���ٹ�
// ���ο� Ǯ�̿���.
// �������� ���������� ǥ���ϴ� r�迭��, �������� ���������� ǥ���ϴ� c�迭�� ���ؼ�
// �� �� �������ٸ� '+',
// �������θ� �������ٸ� '|'
// �������θ� �������ٸ� '-'
// �� ���� �͵��� '.'
// ������ ���� �����ϰ� ������ ��θ� üũ�ؼ� Ȯ���ϴ� ���� ���ٸ� �����̿���.

int n;
string s;
bool r[101][101]; // �������� ������ ��ġ
bool c[101][101]; // �������� ������ ��ġ
int x, y;

// ��� üũ
bool isValidLocation(int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= n || ny >= n)
		return false;

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U')
		{
			if (!isValidLocation(x - 1, y)) continue;

			r[x][y] = true;
			r[--x][y] = true;
		}
		else if (s[i] == 'D')
		{
			if (!isValidLocation(x + 1, y)) continue;

			r[x][y] = true;
			r[++x][y] = true;
		}
		else if (s[i] == 'L')
		{
			if (!isValidLocation(x, y - 1)) continue;

			c[x][y] = true;
			c[x][--y] = true;
		}
		else
		{
			if (!isValidLocation(x, y + 1)) continue;

			c[x][y] = true;
			c[x][++y] = true;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (r[i][j] && c[i][j]) cout << '+';
			else if (r[i][j]) cout << '|';
			else if (c[i][j]) cout << '-';
			else cout << '.';
		}
		cout << '\n';
	}

	return 0;
}