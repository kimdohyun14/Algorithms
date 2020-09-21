#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];
vector<pair<int, pair<int, int> > > edges;
int result;

int FindParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// �������� �����ϱ� ���ؼ� Ʃ���� ù ��° ���Ҹ� ������� ����
		edges.push_back({ cost, {a,b} });
	}

	// ������ �������� ����
	sort(edges.begin(), edges.end());
	int last = 0; // �ּ� ���� Ʈ���� ���ԵǴ� ���� �߿��� ���� ����� ū ����

	// ������ �ϳ��� Ȯ���ϸ鼭
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// ����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
		if (FindParent(a) != FindParent(b)) {
			UnionParent(a, b);
			result += cost;
			last = cost;
		}
	}

	cout << result - last << '\n';
	return 0;
}