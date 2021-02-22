#include <iostream>
#include <vector>
using namespace std;

/*
	�� ������ �˰��� : ����Ʈ�� ���������� �����ؾ� �� ��
	�� ���� ���� �̿��Ͽ� ��ġ�� ����ϸ鼭 ó���ϴ� ���

	O(N)

	�κ� ���� ������ ���� ������ ã������ �� ����ϴ� ����̴�.
*/

int n = 5, m = 5; // �������� ����, �κ� ���� ������ ��
vector<int> v = { 1,2,3,2,5 };

int main()
{
	int sum = 0, cnt = 0;
	for (int left = 0, right = 0; left < n; left++)
	{
		// right�� ������ ��ŭ �̵���Ű��
		while (sum < m && right < n)
		{
			sum += v[right];
			right++;
		}
		// �κ� ���� m�� ��, ī��Ʈ ����
		if (sum == m) cnt++;

		sum -= v[left];
	}

	cout << cnt;
	return 0;
}