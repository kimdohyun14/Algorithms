#include <iostream>
using namespace std;

const int MAX_MONEY = 2100000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int sales_rate = 0;

	// c * sales_rate > a + ( b * sales_rate)
	// c�� b���� �۰ų� ������ ���� ���ͺб����� �Ͼ �� ����.
	// �ݴ�� ũ�ٸ� �Ʒ��� ���� ������ ���´�.
	// sales_rate > a / c - b

	if (c <= b) {
		cout << -1;
	}
	else {
		sales_rate = a / (c - b);
		cout << sales_rate + 1;
	}
	return 0;
}