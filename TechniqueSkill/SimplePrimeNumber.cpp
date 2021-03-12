#include <iostream>
#include <cmath>
using namespace std;

// �Ҽ� �Ǻ� �Լ�, �ð� ���⵵ O(sqrt(n))
bool isPrimeNumber(int x)
{
	// 2���� x�� �����ٱ��� ��� ���� Ȯ���ϸ鼭
	// x�� �ش� ���� ����������ٸ� �Ҽ��� �ƴϴ�.
	for (int i = 2; i <= (int)sqrt(x); i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	cout << isPrimeNumber(4) << endl;
	cout << isPrimeNumber(7) << endl;
	return 0;
}