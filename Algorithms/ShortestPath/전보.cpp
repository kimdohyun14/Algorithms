#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// ����� ���� n, ������ ���� m, ���� ��� ��ȣ start
int n, m, start;
// �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
vector<pair<int, int>> graph[30001];
// �ִ� �Ÿ� ���̺� �����
int d[30001];

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	// ���� ���� ���� ���� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		// ���� �ִ� �Ÿ��� ª�� ��忡 ���� ������ ������
		int dist = -pq.top().first; // ���� �������� ���
		int now = pq.top().second;  // ���� ���
		pq.pop();
		// ���� ��尡 �̹� ó���� ���� �ִ� ����� ����
		if (d[now] < dist) continue;
		// ���� ���� ����� �ٸ� ������ ������ Ȯ��
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			// ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;
	// ��� ���� ������ �Է¹ޱ�
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
		graph[a].push_back({ b,c });
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(d, d + 30001, INF);

	// ���ͽ�Ʈ�� �˰����� ����
	Dijkstra(start);

	// ������ �� �ִ� ����� ����
	int count = 0;
	// ������ �� �ִ� ��� �߿���, ���� �ָ� �ִ� ������ �ִ� �Ÿ�
	int max_distance = 0;
	for (int i = 1; i <= n; i++) {
		// ������ �� �ִ� ����� ���
		if (d[i] != INF) {
			count += 1;
			max_distance = max(max_distance, d[i]);
		}
	}

	// ���� ���� �����ؾ� �ϹǷ� count - 1�� ���
	cout << count - 1 << ' ' << max_distance << '\n';

	return 0;
}