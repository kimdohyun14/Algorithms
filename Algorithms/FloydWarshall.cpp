#include <iostream>
using namespace std;

const int INF = 1000000000;

// �ð� ���⵵ O(N^3)
// ��� �������� ��� ���������� �ִ� ��θ� �� �����ش�.
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// ��� �׷����� �ʱ�ȭ �Ѵ�.
	int dist[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dist[i][j] = a[i][j];
		}
	}

	// k = ���İ��� ���
	for (int k = 0; k < 4; k++) {
		// i = ��� ���
		for (int i = 0; i < 4; i++) {
			// j = ���� ���
			for (int j = 0; j < 4; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	floydWarshall();
	return 0;
}