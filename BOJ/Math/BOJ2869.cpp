#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	
	if (a == v) {
		cout << 1;
	}
	else {
		// n+1 ��° ���� ���� ���� �����̰� �����Ѵٰ� �����ϸ�,
		// n��° ������ �̵��Ÿ��� n * (a - b)
		// n+1 ��° ���� �̵��Ÿ��� a
		// n * (a - b) + a >= v�̸� ����� �� �ִ�.
		// ���� n�� n+1�� ������ ���Ѱ��̹Ƿ� n-1�� �����Ѵ�.
		// �׸��� n�� ���ؼ� �����ϸ� ������ ����.
		double d1 = v - a;
		double d2 = a - b;
		cout << static_cast<int>(ceil(d1 / d2) + 1);
	}
	return 0;
}