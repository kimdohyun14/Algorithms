/*
	�Ǻ���ġ �迭�� 0�� 1�� �����ϸ�, ���� �Ǻ���ġ ���� �ٷ� ���� �� �Ǻ���ġ ���� ���� �ȴ�.
	���� N�� �־�����, N���� ���� ��� ¦�� �Ǻ���ġ ���� ���� ���Ͽ���.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int prev_num = 0, cur_num = 1;
	int next_num = prev_num + cur_num;
	int sum = 0;
	while (next_num < n) {
		if (next_num % 2 == 0) {
			sum += next_num;
		}
		int temp = cur_num + next_num;
		cur_num = next_num;
		next_num = temp;
	}

	cout << sum;

	return 0;
}