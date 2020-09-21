#include <bits/stdc++.h>
using namespace std;

// ����� ����
int v;
// ��� ��忡 ���� ���������� 0���� �ʱ�ȭ
int indegree[501];
// �� ��忡 ����� ���� ������ ��� ���� ���� ����Ʈ �ʱ�ȭ
vector<int> graph[501];
// �� ���� �ð��� 0���� �ʱ�ȭ
int times[501];

// ���� ���� �Լ�
void TopologySort() {
	vector<int> result(501); // �˰��� ���� ����� ���� ����Ʈ
	for (int i = 1; i <= v; i++) {
		result[i] = times[i];
	}

	queue<int> q;
	// ó�� ������ ������ ���������� 0�� ��带 ť�� ����
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	// ť�� �� ������ �ݺ�
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// �ش� ���ҿ� ����� ������ ������������ 1 ����
		for (int i = 0; i < graph[now].size(); i++) {
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]] -= 1;
			// ���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
			if (indegree[graph[now][i]] == 0) {
				q.push(graph[now][i]);
			}
		}
	}

	// ���� ������ ������ ��� ���
	for (int i = 1; i <= v; i++) {
		cout << result[i] << '\n';
	}
}

int main() {
	cin >> v;

	// ���� �׷����� ��� ���� ������ �Է¹ޱ�
	for (int i = 1; i <= v; i++) {
		// ù ��° ���� �ð� ������ ��� ����
		int x;
		cin >> x;
		times[i] = x;
		// �ش� ���Ǹ� ��� ���� ���� ���� �ϴ� ���ǵ��� ��ȣ �Է�
		while (true) {
			cin >> x;
			if (x == -1) break;
			indegree[i] += 1;
			graph[x].push_back(i);
		}
	}

	TopologySort();
	return 0;
}