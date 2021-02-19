#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void input()
{
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
}

bool calc(long long mid)
{
	int cnt = 1; // ��緹���� ����
	int sum = 0; // ������� ���� ������ ��
	for (int i = 0; i < n; i++)
	{
		// �ϳ��� ������ ��緹�� ũ�⺸�� ũ�� �Ұ���
		if (v[i] > mid)  return false;
		sum += v[i];
		
		// �ϳ��� �� ��Ҵµ� ��緹�̰� ���� ��� -> �߰�
		if (sum > mid)
		{
			sum = v[i];
			cnt++;
		}
	}

	// ������ �����Ѵٸ�(��緹�� ������ ������ ���̷��� �Ѵ�)
	if (cnt <= m) return true;
	else return false;
}

void solve()
{
	input();

	long long left = 0, right = 1e9;
	long long answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		// ��緹�� ũ�⸦ �ּҷ� �ϸ鼭 ���ÿ� ��緹���� ������ ���̴� ���ǿ� �����Ѵٸ�
		if (calc(mid))
		{
			answer = mid;
			right = mid - 1;
		}
		else // �׷��� �ٿ����ϱ� ������ ��緹�� ũ�⸦ �� ũ�� �����Ѵ�.
			left = mid + 1;
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}