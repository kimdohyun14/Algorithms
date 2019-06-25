#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20001
#define INF 987654321
using namespace std;

vector<pair<int, int>> barn[MAX];

vector<int> hideAndSeek(int start, int size) {
	vector<int> dist(size + 1, INF); //start���κ��� �� ����� �ִ� ��θ� ����
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(dist[start], start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue; //���ʿ��� ���� x
		for (int i = 0; i < barn[cur].size(); i++) {
			int next = barn[cur][i].first;
			int distance = barn[cur][i].second + cost;

			if (dist[next] > distance) { //�� ª�� ��ΰ� �ִٸ� ����
				dist[next] = distance;
				pq.push(make_pair(distance, next));
			}
		}
	}
	return dist;
}

int main() {
	int M, N;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		barn[from].push_back(make_pair(to, 1));
		barn[to].push_back(make_pair(from, 1));
	}

	vector<int> dist = hideAndSeek(1, N);
	int max = 0, findLittleNode = 1;
	//���� �ָ��ִ� �갣�� ��带 ã�´�.
	for (int i = 1; i < dist.size(); i++) {
		if (max < dist[i]) {
			max = dist[i];
			findLittleNode = i;
		}
	}
	int cnt = 0;
	//�� �갣�� ���� �Ÿ��� �� ������ cnt����
	for (int i = 1; i < dist.size(); i++) {
		if (max == dist[i]) {
			cnt++;
		}
	}
	printf("%d %d %d", findLittleNode, dist[findLittleNode], cnt);
	
	return 0;
}