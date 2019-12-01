#include <iostream>
using namespace std;

bool prime[1000001]; 

// 2���� 100������ �Ҽ��� ��� ���س��´�. (�����佺�׳׽��� ü)
// O(NloglogN)
void eratosthenes()
{
	prime[1] = true;

	// ���� �������� ���� �� �߿��� ���� ���� ���� ã�´�.
	for (int i = 2; i <= 1000000; i++)
	{
		// �� ���� �Ҽ����
		if (prime[i] == false)
		{
			// �� ���� ����� ��� �����.
			for (int j = i + i; j <= 1000000; j += i)
			{
				prime[j] = true;
			}
		}
	}
}

int main()
{
	eratosthenes(); // �̸� �Ҽ��� ��� ���س��� ������ �ذ��Ѵ�.
	
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
		if (prime[i] == false)
			cout << i << '\n';
	}

	return 0;
}