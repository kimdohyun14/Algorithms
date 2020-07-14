#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& v, int n)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = 0; k < v.size(); k++)
			{
				// 3���� �ﰢ���� ������ ǥ���Ǵ� �ڿ����̸�
				if (n == v[i] + v[j] + v[k])
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int k;
	cin >> k;
	// �ﰢ���� �̸� ���� ���´�.
	vector<int> v;
	for (int i = 1; i <= 50; i++)
	{
		int t = (i * (i + 1)) / 2;
		v.push_back(t);
	}

	while (k--)
	{
		int n;
		cin >> n;
		if (solve(v, n)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}