#include <bits/stdc++.h>
using namespace std;

// �Ǻ���ġ ���� : ���� �� ���� ���� ������ ������ �����ϴ� ����


// �ð� ���⵵ O(2^N) ���� �ð��� �ҿ�
// N = 30, 10�� ������ ������ ����
// F(n)���� n�� Ŀ���� Ŀ������ �ݺ��ؼ� ȣ���ϴ� ���� ��������.

// �Ǻ���ġ �Լ��� ����Լ��� ����
int Fibo(int x) {
	if (x == 1 || x == 2)  return 1;
	return Fibo(x - 1) + Fibo(x - 2);
}

int main() {
	cout << Fibo(4) << '\n';
	return 0;
}