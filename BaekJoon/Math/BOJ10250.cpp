#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++) {
		int h, w, n;
		cin >> h >> w >> n;
		// ȣ�� ���ڸ� ���ȣ, ���ڸ� ���ȣ
		int first_room_number = 0, last_room_number = 0;

		// N��° �մ��� ������ ��� ���ϴ��� (���ڸ�)
		for (int i = 1; i <= w; i++) {
			if (i * h >= n) {
				last_room_number = i;
				break;
			}
		}
		// N��° �մ��� ������ ��������� (���ڸ�)
		for (int i = 0; i < h; i++) {
			if (n == last_room_number * h - i) {
				first_room_number = h - i;
				break;
			}
		}
		
		// ���ڸ� ��ȣ�� 10���� �۴ٸ� 0�� ���Խ��Ѽ� ���
		if (last_room_number < 10) {
			cout << first_room_number << 0 << last_room_number << '\n';
		}
		else { // �ƴ϶�� �׳� ���ڸ� + ���ڸ�
			cout << first_room_number << last_room_number << '\n';
		}
	}
	return 0;
}