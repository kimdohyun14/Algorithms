#include <iostream>
#include <vector>
using namespace std;

// ���� https://baactree.tistory.com/29
// ���� ���⵵�� ���α׷��� �޸� ��뷮�� �м��ϴ� ���̴�.
// ����� �迭�� ũ�� * (�ش� �ڷ����� ũ��)
// ���� ��Ÿ ���������� �������, �Լ� ���� �����ؼ� 5~10MB������
// ������ ���� �����Ѵ�.

// �ð� ���⵵�� ���α׷� ����ð��� �м�
// �ݺ����� ũ�� ������ �޴´�.
// ��� ǥ������� �Է��� ũ�Ⱑ n�� ��
// �־��� ���α׷��� ����ð��� 5n^4-7n^3+n^2+4�� ���� �����ٸ�
// �ð����⵵�� O(N^4)�� ���� ǥ��.
// PS������ ���� 1���� 1�ʷ� ��� ����Ѵ�.

// �־��� �Է��� ũ�Ⱑ n�̶�� �Ͽ��� ��,
// �־��� ������� ������ �Ʒ��ΰ� �� (���� -> ����) ���̴�.

// O(logN)
while (n) {
	n /= 2;
}

// O(sqrt(N))
for (int i = 0; i * i <= n; i++);

// O(N)
for (int i = 0; i < n; i++);

// O(NlogN)
for (int i = 0; i < n; i++)
	for (int j = i; j; j /= 2);

// O(Nsqrt(N))
for (int i = 0; i < n; i++)
	for (int j = 0; j * j <= i; j++);

// O(N^2)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++);

// O(N^3)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++);

// O(2^N)
int function(int n) {
	if (n == 0 || n == 1)
		return 1;
	return function(n - 1) + function(n - 2);
}

// O(N!)
// N���� �����͸� �����ϴ� ����� ��
void function(int x, vector<int> pick, vector<bool> picked) {
	if (x == n) {
		for (int i = 0; i < pick.size(); i++) {
			cout << pick[i] << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (picked[i])
			continue;
		pick.push_back(i);
		picked[i] = true;
		function(x + 1, pick, picked);
		pick.push_back();
		picked[i] = false;
	}
	return;
}
