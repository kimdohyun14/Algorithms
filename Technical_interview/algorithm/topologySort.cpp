#include <bits/stdc++.h>
using namespace std;

int v, e;
int indegree[100001];
vector<int> graph[100001];

vector<int> topologySort() {
	vector<int> result;
	queue<int> q;

	// ���������� 0�� ��带 �־��ش�.
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	// ��� ��� �ݺ�
	for (int i = 1; i <= v; i++) {
		// n���� ��带 �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �߻��� ��
		if (q.empty()) {
			cout << "����Ŭ�� �߻�\n";
			return result;
		}
		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	return result;
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	vector<int> result = topologySort();
	for (auto n : result) {
		cout << n << ' ';
	}
	return 0;
}