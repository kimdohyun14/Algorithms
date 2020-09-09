#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

// ���� ������ �ð����⵵ O(V+E)
// ������ ���� + ������ ������ŭ
// �׷����� ������ 2�� �������·� �����߱� ������,
// 2���� �迭���� �޸� ����� ���� ��, E��ŭ�� Ž���ϱ� �����̴�.
// ���� vector�� ���� ����Ʈ�� ȿ���� �� �� �ִ�.

int n, inDegree[MAX]; // ���������� �ǹ�
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// ���� ������ 0�� ��带 ť�� �����Ѵ�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	// ���� ������ ������ ����Ƿ��� ��Ȯ�� N���� ��带 �湮�Ѵ�.
	for (int i = 1; i <= n; i++) {
		// N���� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �߻��� ��
		if (q.empty()) {
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x; // ��θ� �����ϱ� ���ؼ�
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i]; // ���� x�� ����Ǿ��ִ� ���
			// ����Ǿ��ִ� ��� �������� ���������� -1 ���ҽ�Ų��.
			// �̴� ���� ���� ������ ������ش�.
			--inDegree[y];
			if (inDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	topologySort();
	return 0;
}