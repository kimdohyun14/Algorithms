#include <iostream>
using namespace std;

const int INF = 1000000000;

// ����Ž������ ���ͽ�Ʈ�� ����
// �ð� ���⵵ O(N^2)
// ���� : ���� �湮���� �ʴ� ���� �߿��� �ּ� �Ÿ��� ������ ��带
//        �����ϴ� ����� O(N)�� ��� ����

// �׷��� ǥ��
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};
bool check[6];  // �湮�� ���
int dist[6];    // �ִ� �Ÿ�

// ���� �ּ� �Ÿ��� ������ ������ ��ȯ�Ѵ�.
// �̴� ���� �湮���� ���� ���� �߿��� �ּ� �Ÿ��� ������ ��带 ����
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < 6; i++) {
		if (dist[i] < min && !check[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < 6; i++) {
		dist[i] = a[start][i];
	}
	check[start] = true;
	for (int i = 0; i < 6 - 2; i++) {
		int current = getSmallIndex();
		check[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!check[j]) {
				if (dist[current] + a[current][j] < dist[j]) {
					dist[j] = dist[current] + a[current][j];
				}
			}
		}
	}
}

int main() {
	dijkstra(0);
	for (int i = 0; i < 6; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}