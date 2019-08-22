#include <iostream>
using namespace std;

int new_number;
int temp;
int old_first, old_second;

int PlusCycle(int target) {
	// 10���� ������ �տ� 0�� �ٿ��ش�.
	if (target < 10) {
		// ���࿡ 1�̸� 01�� �ȴ�.
		// �� �� target�� ���� �ڸ��̹Ƿ�
		old_first = 0;
		old_second = target;

		temp = old_first + old_second;
		new_number = old_second * 10 + temp % 10;
	}
	else {
		// ����� �� �� ���ְ� �ݺ����� ����.
		// �־��� ���� �� �ڸ� ���ڸ� ���Ѵ�.
		old_first = target / 10;
		old_second = target % 10;

		temp = old_first + old_second;
		// ���ο� ����  �־��� ���� ���� �ڸ���, �� �ڸ��� ������ ���� �̾���δ�.
		new_number = old_second * 10 + temp % 10;
	}

	return new_number;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cycle_length = 1;
	int target;
	cin >> target;

	new_number = PlusCycle(target);

	//cout << new_number << endl;

	while (new_number != target) {
		cycle_length++; // ���ϱ� ����Ŭ�� ���� �ø���.

		new_number = PlusCycle(new_number);
		//cout << new_number << endl;
	}
	cout << cycle_length;
	return 0;

}