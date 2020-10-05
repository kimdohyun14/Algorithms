#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;

// ���� [left_value, right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
int countByRange(vector<int>& v, int leftValue, int rightValue) {
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int main() {
	cin >> n >> x;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	// ���� [x, x] ������ �ִ� �������� ���� ���
	int cnt = countByRange(v, x, x);

	// ���� x�� ���Ұ� �������� �ʴ´ٸ�
	if (cnt == 0) cout << -1 << '\n';
	else cout << cnt << '\n';
	return 0;
}