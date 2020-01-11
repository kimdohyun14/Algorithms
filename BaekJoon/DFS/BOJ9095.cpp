#include <iostream>
using namespace std;

int solve(int sum, int goal) {

	// �Ұ����� ���
	if (sum > goal) return 0;
	// ��������
	if (sum == goal) {
		return 1;
	}

	// ������ �� �� �ִ� ���
	// 1�� ���ϰų�, 2�� ���ϰų�, 3�� ���ϴ� ��츦 ��� ���ؼ� �����Ѵ�.
	int ans = 0;
	for (int number = 1; number <= 3; number++) {
		ans += solve(sum + number, goal);
	}

	// ���� �� �ִ� ����� ���� ��ȯ�Ѵ�.
	return ans;
}

int main() {
	int tc;
	cin >> tc;

	for (int test_case = 0; test_case < tc; test_case++) {
		int make_number;
		cin >> make_number;
		cout << solve(0, make_number) << '\n';
	}
	return 0;
}