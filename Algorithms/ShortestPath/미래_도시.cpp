#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// ����� ���� n, ������ ���� m
int n, m;
// 2���� �迭
int graph[101][101];

int main() {
	cin >> n >> m;

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
		}
	}

	// �� ������ ���� ������ �Է� �޾�, �� ������ �ʱ�ȭ
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// a�� b�� ���ο��� ���� ����� 1�̶�� ����, ����� ����
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// ���� �� ��� x�� ���� ������ ��� k�� �Է� �ޱ�
	int x, k;
	cin >> x >> k;

	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// ����� ����� ���
	int distance = graph[1][k] + graph[k][x];

	// ������ �� ���� ���, -1�� ���
	if (distance >= INF)
		cout << -1 << '\n';
	else
		cout << distance << '\n';
	return 0;

}