#include <iostream>
using namespace std;

// �ܼ��ϰ� ���� ���� ����� �̿��ؼ� �Ǻ���ġ ������ ���Ѵٸ�
// �ð� ���⵵ O(N^2)

int fibonacci(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	return fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
	cout << fibonacci(10) << '\n';
	//cout << fibonacci(50) << '\n'; ���� �ð��� �ҿ�ȴ�.
	return 0;
}