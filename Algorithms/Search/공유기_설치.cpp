#include <bits/stdc++.h>
using namespace std;

/*
	Ư�� �������� ������ ��ġ�� �����⸦ ��ġ�Ѵ�.
	��ġ�� ���� �� ������ ���� �Ǵ��Ѵ�.
	�����Ⱑ �� ��ġ�Ƿ���, ������ ���δ�.
	�����Ⱑ �� ��ġ�Ƿ���, ������ �ø���.
*/

int n, c;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int left = 1;
	int right = v[n - 1] - v[0];
	int distance = 0;
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int start = v[0];
		int cnt = 1; // �������� ��ġ ��

		// ������ distance �������� ������ ��ġ�Ѵ�.
		for (int i = 1; i < n; i++) {
			distance = v[i] - start;
			if (mid <= distance) {
				cnt++;
				start = v[i];
			}
		}
		
		// �������� ���� ������ => ���� ������
		if (cnt >= c) {
			answer = mid;
			left = mid + 1;
		}
		// �������� ���� �ø��� => ���� ������
		else {
			right = mid - 1;
		}
	}

	cout << answer << '\n';
	return 0;
}