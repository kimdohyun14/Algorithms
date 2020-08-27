#include <iostream>
#include <vector>
using namespace std;

// �����佺�׳׽��� ü
// �뷮�� �Ҽ��� ������ ���ϴ� �˰���
// O(NloglogN)

// ���۹��
// 1. 2 ~ N���� ��� ���� ����´�.
// 2. ���� �������� ���� �� �߿��� ���� ���� ���� ã�´�.
// 3. �� ���� �Ҽ��̰�,
// 4. �� ���� ����� ��� �����.

const int MAX = 100001;
bool prime[MAX];

void eratosthenes()
{
	prime[1] = true;

	for (int i = 2; i <= MAX; ++i)
	{
		// �� ���� �Ҽ����
		if (prime[i] == false)
		{
			// �� ���� ������� ��� �����.
			for (int j = i + i; j <= MAX; j += i)
			{
				prime[j] = true;
			}
		}
	}
}

int main()
{
	// �뷮�� �Ҽ��� ���ϰ�
	eratosthenes();

	// ���� �Ҽ��� ���� ����.
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
		if (prime[i] == false)
			++cnt;

	cout << "�� �Ҽ��� �� : " << cnt << endl;
	return 0;
}