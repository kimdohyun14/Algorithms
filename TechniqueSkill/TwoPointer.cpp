#include <iostream>
using namespace std;

/*
	# �� ������ �˰���
	����Ʈ�� ���������� �����ؾ� �� �� 2���� ���� ��ġ�� ����ϸ鼭 ó��

	ex) Ư���� ���� ������ �κ� ���� ���� ã�� ����

	# ���� ���
	1. ������(start)�� ����(end)�� ù ��° ������ �ε����� ����Ű���� �Ѵ�.
	2. ���� �κ����� M�� ���ٸ� ī��Ʈ�Ѵ�.
	3. ���� �κ����� M���� ������ end�� 1 ������Ų��.
	4. ���� �κ����� M���� ũ�ų� ������ start�� 1 ������Ų��.
	5. ��� ��츦 Ȯ���� ������ 2������ 4�������� ������ �ݺ��Ѵ�.
*/

int n = 5; // �������� ����
int m = 5; // ã���� �ϴ� �κ���
int arr[] = { 1,2,3,2,5 }; // ��ü ����

int main()
{
	int cnt = 0;
	int intervalSum = 0;
	int end = 0;

	// start�� ���ʴ�� ������Ű�� �ݺ�
	for (int start = 0; start < n; start++)
	{
		// end�� ������ ��ŭ �̵���Ű��
		while (intervalSum < m && end < n)
		{
			intervalSum += arr[end];
			end++;
		}
		// �κ����� m�� �� ī��Ʈ ����
		if (intervalSum == m) cnt++;
		intervalSum -= arr[start];
	}

	cout << cnt << '\n';
	return 0;
}