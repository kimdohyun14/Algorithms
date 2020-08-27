#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// � �� N�� �Ҽ����� �ƴ��� �Ǻ��ϴ� ���
// �ҷ��� �Ҽ��� ���� �� ����
// �Ҽ��� 2���� ũ�ų� ����, N-1 ���� �۰ų� ���� �ڿ����� ���� �������� �ȵ�.
// ���⼭ 2 ~ N-1�� ������ �͵� ����������,
// 2 * 4 = 4 * 2 ó�� ��Ī�� �̷�� ������
// Ư���� ������ �����ٱ����� ����� ���θ� �����ϸ� �ȴ�.
// �ð� ���⵵ O(sqrt(N))

bool IsPrime(int n)
{
	if (n < 2) return false;
	// 2 <= i <= sqrt(N)
	// i * i <= n
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	vector<int> v = { 1, 19, 24, 65, 98, 37, 11, 33, 28 };
	for (int i = 0; i < v.size(); ++i)
	{
		if (IsPrime(v[i]))
			cout << v[i] << "�� �Ҽ��Դϴ�." << endl;
		else
			cout << v[i] << "�� �Ҽ��� �ƴմϴ�." << endl;
	}

	return 0;
}