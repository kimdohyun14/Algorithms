#include <iostream>
#include <algorithm>
using namespace std;

string a[1001];
int n;

int get_sum(string a) {
	int length = a.length();
	int sum = 0;
	for (int i = 0; i < length; i++) {
		// ������ ��쿡�� ������.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
			sum += (a[i] - 48);
	}
	return sum;
}

bool compare(string a, string b) {
	// ���̰� ª�� ���� �켱
	if (a.length() < b.length()) {
		return 1; // �켱������ ���� �ο�
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {
		// ���̰� ���� ���
		int a_sum = get_sum(a);
		int b_sum = get_sum(b);
		// �� ���ڿ��� ������ ���� ���ؼ�
		if (a_sum != b_sum)
			return a_sum < b_sum; // �� ���� ������
		else
			return a < b; // ������
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		// ������ ���ڿ��� ���ؼ��� �����Ѵ�. (����� �� ����)
		if (i > 0 && a[i] == a[i - 1])
			continue;
		else
			cout << a[i] << '\n';
	}
	return 0;
}