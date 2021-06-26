#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// greedy
// ó������ ��� �ִ�� �ּҷ� ������ ������ �� ������ ������ �ϴٰ�,,
// �ᱹ �� Ǯ� �ٸ� ����� Ǭ �ش��� Ȯ���غ��� �㹫�ߴ�..
// �������� "������ �ְ��� ���ò��̱� ������ 
// �׻� ���ӿ��� ȹ���� �� �ִ� �ְ��� ������ ��´ٴ� ����� �ڸ��ϴ�."
// ��� ������ �ֱ� ������ �ᱹ 1������ ���밪�� 2������ ���밪�� ���� �����̴�.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> r1(n);
	vector<int> r2(n);
	for (int i = 0; i < n; i++) cin >> r1[i];
	for (int i = 0; i < n; i++) cin >> r2[i];

	int ans = 0;
	for (int i = 0; i < n; i++) ans += abs(r1[i]) + abs(r2[i]);
	cout << ans << '\n';
	return 0;
}