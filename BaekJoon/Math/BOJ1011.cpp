#include <iostream>
using namespace std;

// ���� : http://blog.naver.com/occidere/220982644540
// �� ������ ��Ģ�� ã�Ƽ� Ǫ�� ����

int warp(int dist) {
	long long n, min_n, pow_n, max_n, warp_count = 0;
	// y - x = dist
	// dist �Ÿ��� ��� ������ �����ִ��� ã��
	// �� ���غ��� ������ ū���� Ȯ���ϸ� �ȴ�.
	for (n = 1; ; n++) {
		pow_n = n * n;
		min_n = pow_n - n + 1;
		max_n = pow_n + n;
		if (min_n <= dist && dist <= max_n) {
			if (min_n <= dist && dist <= pow_n)
				warp_count = 2 * n - 1;
			else
				warp_count = 2 * n;
			break;
		}
	}
	return warp_count;
}

int main() {
	int t;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int x, y;
		cin >> x >> y;
		cout << warp(y - x) << '\n';
	}
	return 0;
}