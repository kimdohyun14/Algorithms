/*
	�Ǻ���ġ �迭�� 0�� 1�� �����ϸ�, ���� �Ǻ���ġ ���� �ٷ� ���� �� �Ǻ���ġ ���� ���̴�.
	���� N�� �־�����, N���� ���� ��� ¦�� �Ǻ���ġ ���� ���� ���ض�.
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int prev = 0, cur = 1;
	int next = prev + cur;
	int sum = 0;
	while (next < n) {
		if (next % 2 == 0) {
			sum += next;
		}

		int temp = cur + next;
		cur = next;
		next = temp;
	}

	cout << sum;
	return 0;
}