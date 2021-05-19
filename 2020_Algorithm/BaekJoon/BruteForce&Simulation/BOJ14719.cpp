// https://machine-geon.tistory.com/140 
// ���߿� �ٽ� Ǯ���.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int h, w, answer;
vector<int> v;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	for (int i = 1; i < w - 1; i++) {
		int left = 0;
		int right = 0;

		// ���ʿ��� ���� ���� �ǹ��� ����
		for (int j = 0; j < i; j++) left = max(left, v[j]);
		// �����ʿ��� ���� ���� �ǹ��� ����
		for (int j = i + 1; j < w; j++) right = max(right, v[j]);
		// �� ���� �ǹ��� �������� ���� �ε����� ���̴� ����
		if (v[i] < left && v[i] < right) answer += min(left, right) - v[i];
	}

	cout << answer << '\n';
	return 0;
}