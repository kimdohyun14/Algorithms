#include <iostream>
using namespace std;

int n, k, cnt;

int main()
{
	cin >> n >> k;

	while (1)
	{
		// N�� K�� ������ �������� ���� �� �������� 1�� ����
		int target = (n / k) * k;
		cnt += (n - target);
		n = target;
		// N�� K���� ���� �� Ż��
		if (n < k) break;
		cnt++;
		n /= k;
	}

	// ���������� ���� ���� ���Ͽ� 1�� ����
	cnt += (n - 1);
	cout << cnt << '\n';
	return 0;
}