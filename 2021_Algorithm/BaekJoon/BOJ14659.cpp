#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// greedy, or bruteforce
// ���츮�� ������ ������ �������� ���츮�� Ȯ���ϸ鼭 ������ ���� ���츮�� ���� ����ؼ� �����س�����.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = 0;
	int i = 0, j = 0;
	while (1) {
		if (i >= n || j >= n) break;
		while (j + 1 < n && v[i] > v[j + 1]) j++;

		ans = max(ans, j - i);
		i++;
		j = i;
	}

	cout << ans << '\n';
	return 0;
}