#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	double dNum = 1234.56789;
	printf("dNum : %lf\n", dNum);
	// �Ҽ��� �Ʒ��� �ڸ��� = %f ���� �����ʿ� �ִ� ��
	// �� �ڸ����� ���߱� ���� �ڵ����� ���� ��Ȧ���Ͽ� �����
	// C style
	printf("%.0f\n", dNum);
	printf("%.1f\n", dNum);
	printf("%.2f\n", dNum);
	printf("%.3f\n", dNum);
	printf("%.4f\n\n", dNum);

	printf("dNum : %lf\n", dNum);
	// C++ style
	cout << dNum << '\n'; // �ƹ��� ���� ���� ������� ��, ��ü �ڸ����� 6���� ����, ���������� �ڵ����� �ݿø�

	cout.precision(5);    // �ڸ����� �����ϴ� �Լ�, ��ü �ڸ����� 5�� ������ ��
	cout << dNum << '\n';

	cout << fixed;        // �Ҽ��� �Ʒ� ���� �����ϴ� ǥ���̴�.
	cout.precision(6);    // fixed ���Ŀ� precision�� �Է��ϸ� �Ҽ��� �Ʒ��� 6���� �����Ѵٴ� ��
	cout << dNum << '\n';

	cout.unsetf(ios::fixed); // .setf�� �ݴ�Ǵ� ǥ���� .unsetf�̸�, �̴� ���� ������ �ǹ��Ѵ�.
	cout << dNum << '\n';

	cout.setf(ios::fixed); // .fixed��� ǥ���� .setf(ios::fixed)�� ����� �� �ִ�.
	cout.precision(5);     // ���Ŀ� �Ҽ��� �Ʒ� �ڸ����� 5�� �����ߴ�.
	cout << dNum << '\n';
	return 0;
}