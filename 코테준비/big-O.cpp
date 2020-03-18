// ��ó : https://baactree.tistory.com/26?category=732753
#include <iostream>
using namespace std;

// ���⵵ �м��ϱ�
// PS���� ���Ǵ� ���⵵�� �ð����⵵�� �������⵵
// �ð����⵵(TimeComplexity) : ���α׷� ����ð��� �м��ϴ� ��
// �������⵵(SpaceComplexity) : ���α׷��� �޸� ��뷮�� �м��ϴ� ��

// �ð����⵵
// o(5n^4 + 3n^2) => o(n^4)
// ���� ũ�� ������ �޴� �׸� ǥ���Ѵ�.

// �������⵵
// �迭�� ũ�� x �ش� �ڷ����� ũ��
// ���� ��Ÿ ���������� �������, �Լ����� �����ؼ� 5 ~ 10MB ������ ������ ���� ����


int n;

// o(logN)
while (n)
	n /= 2;

// o(sqrt(N))
for (int i = 0; i * i <= n; i++);

// o(N)
for (int i = 0; i < n; i++);

// o(N * logN)
for (int i = 0; i < n; i++)
	for (int j = i; j < n; j /= 2);

// o(N * sqrt(N))
for (int i = 0; i < n; i++)
	for (int j = 0; j * j <= i; j++);

// o(N * N) = o(N^2)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++);

// o(N * N * N) = o(N^3)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++);

// o(2 ^ N)
// �ϳ��� �Լ� �ȿ� �� ���� �Լ��� ȣ���� ��
int function(int n)
{
	if (n == 0 || n == 1) return 1;
	else return function(n - 1) + function(n - 2);
}

// o(N!)
// N���� �����͸� �����ϴ� ����� ��
// ���� (permutation) �κе� ���
// ���⼭�� i��°���� ������ �ϴ� ���, ���ϴ� ���� ������ ����ϴ� ���
void function(int x, vector<int>& pick, vector<bool>& picked)
{
	// ������ ���
	if (x == n)
	{
		for (int i = 0; i < pick.size(); i++)
			printf("%d\n", pick[i]);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (picked[i]) continue; // ���É�ٸ� �н�
		pick.push_back(i);
		picked[i] = true;
		function(x + 1, pick, picked); // i�� pick�߰� �������� �Ѿ��
		pick.pop_back();  // ������ �Ϸ��ϱ�
		picked[i] = false;
	}
	return;
}
