#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

// ġŲ �Ÿ��� ���� ���ϴ� �Լ�
int GetSum(vector<pair<int, int>>& candidates) {
	int result = 0;
	// ��� ���� ���Ͽ�
	for (int i = 0; i < house.size(); i++) {
		int hx = house[i].first;
		int hy = house[i].second;
		// ���� ����� ġŲ ���� ã��
		int temp = 1e9;
		for (int j = 0; j < candidates.size(); j++) {
			int cx = candidates[j].first;
			int cy = candidates[j].second;
			temp = min(temp, abs(hx - cx) + abs(hy - cy));
		}
		// ���� ����� ġŲ �������� �Ÿ��� ���ϱ�
		result += temp;
	}
	// ġŲ �Ÿ��� �� ��ȯ
	return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i,j });
			else if (arr[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	// ��� ġŲ �� �߿��� m���� ġŲ ���� �̴� ���� ���
	vector<int> order(chicken.size());
	fill(order.end() - m, order.end(), 1);

	// ġŲ �Ÿ��� ���� �ּҸ� ã�� ���
	int result = 1e9;

	do {
		vector<pair<int, int>> now;
		for (int i = 0; i < chicken.size(); i++) {
			if (order[i]) {
				int cx = chicken[i].first;
				int cy = chicken[i].second;
				now.push_back({ cx,cy });
			}
		}
		result = min(result, GetSum(now));
	} while (next_permutation(order.begin(), order.end()));
	cout << result << '\n';
	return 0;
}