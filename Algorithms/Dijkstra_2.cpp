#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���ͽ�Ʈ�� �� ������ �̿��ؼ� ����
// �� ���� -> �켱���� ť
// �켱���� ť�� ���ؼ� ���� �湮���� ���� ���� �� ���� ����� ����
// ��带 �����ϴ� ����� logE�ۿ� ���� �ʱ� ������ �ð��� �����ų �� �ִ�.
// �ð� ���⵵ O(ElogE)

const int INF = 1000000000;

vector<pair<int, int>> a[7]; // ���� ����
int dist[7];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; // (first : ���, second : ���)
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (dist[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			// ������ �ּ� ��뺸�� �� ���� �۴ٸ� �����Ѵ�.
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main() {
	// �⺻������ ������� ���� ��� ����� �������� �����Ѵ�.
	for (int i = 1; i <= 6; i++) {
		dist[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);
	for (int i = 1; i <= 6; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}