#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// ����� ���� n, ������ ���� m
// ����� ������ �ִ� 500����� ����
int n, m;
// 2���� �迭 �����
int graph[501][501];

int main() {
	cin >> n >> m;

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 501; i++) {
		fill(graph[i], graph[i] + 501, INF);
	}

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}

	// �� ������ ���� ������ �Է� �޾�, �� ������ �ʱ�ȭ
	for (int i = 0; i < m; i++) {
		// a���� b�� ���� ����� c��� ����
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	// ����� ����� ���
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			// ������ �� ���� ���, ���� ���
			if (graph[a][b] == INF)
				cout << "INFINITY" << " ";
			else
				cout << graph[a][b] << ' ';
		}
		cout << '\n';
	}
	return 0;
}