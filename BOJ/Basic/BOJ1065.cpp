#include <iostream>
#include <vector>
using namespace std;

// � ���� ���� x�� �ڸ����� ���������� �̷�ٸ�
bool IsOrderSequence(int x) {
	if (x < 10) return true;

	vector<int> v;
	int temp = 0;
	while (x) {
		temp = x % 10;
		x /= 10;
		v.push_back(temp);
	}

	int diff = v[1] - v[0];
	// �� �ڸ����� ���̰� ������ ���̷� �־�� �Ѵ�.
	for (int i = 2; i < v.size(); i++) {
		if (v[i] - v[i - 1] != diff)
			return false;
	}
	return true;
}

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (IsOrderSequence(i))
			ans++;
	}
	cout << ans;
	return 0;
}