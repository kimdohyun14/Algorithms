#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int s = 0, e = 1e9;
	int answer = 0;

	while (s <= e)
	{
		long long total = 0;
		int mid = (s + e) / 2;
		for (int i = 0; i < n; i++)
		{
			// �߶��� ���� ���� �� ���
			if (v[i] > mid)
				total += v[i] - mid;
		}

		if (total < m) // ���� ���� ������ ��� �� ���� �ڸ��� (���� �κ� Ž��)
			e = mid - 1;
		else
		{
			// ���� ���� ����� ��� �� �ڸ��� (������ �κ� Ž��)
			answer = mid; // �ִ��� �� �߶��� ���� �����̹Ƿ�, ���⿡�� ���� ���
			s = mid + 1;
		}
	}

	cout << answer << endl;
	return 0;
}