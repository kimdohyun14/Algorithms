#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ���ٹ�
// ��� �ִ� �簢���� ���̸� ã�´�.
// ã�� ����� �� ���� ���̸� �������� �� ���� ���̿� ���� ������ ����
// ��ü �簢���� �ʺ� �Ǵ� ������ ��� �츮�� ã�� �� �簢���� �ʺ� �Ǵ� ������ ���̴�.

int k;
int w, h;
int ww, hh;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k;
	vector<int> v(6);
	for (int i = 0; i < 6; i++)
	{
		int tmp;
		cin >> tmp >> v[i];
		if (i % 2 == 0)
			h = max(h, v[i]);
		else
			w = max(w, v[i]);
	}

	// �� ���� �������� ����,
	// ���� ���� ���� ���� ���� ��ü �簢���� �ʺ� �Ǵ� ������ ���
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			if (w == v[(i + 5) % 6] + v[(i + 1) % 6])
				hh = v[i];
		}
		else
		{
			if (h == v[(i + 5) % 6] + v[(i + 1) % 6])
				ww = v[i];
		}
	}
	cout << (w * h - ww * hh) * k;
	return 0;
}