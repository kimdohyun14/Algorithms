#include <iostream>
using namespace std;

// ���� : https://mygumi.tistory.com/325

// �ּ� ������� ��Ŭ���� ȣ�������� ���Ѵ�.
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		// x�� ������Ű�� m��ŭ �����ϸ鼭 y�� ã���ش�.
		int cnt = x;
		int move_y = x;

		for (int i = 0; i < n; i++) {
			int temp = move_y % n == 0 ? n : move_y % n;
			if (temp == y)
				break;

			move_y = temp + m;
			cnt += m;
		}
		// �� ���� �ּ� ����� ���� ũ�ٸ� ���� ���� ����̹Ƿ�
		if (cnt > lcm(m, n)) {
			cout << -1 << '\n';
		}
		else {
			cout << cnt << '\n';
		}
	}
	return 0;
}