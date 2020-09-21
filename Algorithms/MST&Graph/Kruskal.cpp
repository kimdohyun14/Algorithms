#include <bits/stdc++.h>
using namespace std;

// ���� Ʈ�� �߿��� �ּ� ������� ���� �� �ִ� ���� Ʈ���� ã�� �˰���
// ũ�罺Į �˰����� ���� �Ÿ��� ª�� �������� ���ʴ�� ���տ� �߰��ϰų� �߰����� �ʴ´�.
// �ð� ���⵵ O(ElogE)
// �ð��� ���� ���� �ɸ��� �κ��� ���� �κ��̹Ƿ�, ���μ� ���� �˰����� �ð� ���⵵�� �����Ѵ�.

// ����� ���� v, ����(union)�� ���� e
// ����� ������ �ִ� 100,000����� ����
int v, e;
int parent[100001];
// ��� ������ ���� ����Ʈ��, ���� ����� ���� ����
vector<pair<int, pair<int, int> > > edges;
int result;

// Ư�� ���Ұ� ���� ������ ã��
int FindParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
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

	// ��� ������ ���� ������ �Է� �ޱ�
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// �������� �����ϱ� ���ؼ� Ʃ���� ù ��° ���Ҹ� ������� ����
		edges.push_back({ cost, {a,b} });
	}
	
	// ������ �������� ����
	sort(edges.begin(), edges.end());

	// ������ �ϳ��� Ȯ���ϸ�
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// ����Ŭ�� �߻����� ���� ��쿡�� ���տ� ����
		if (FindParent(a) != FindParent(b)) {
			UnionParent(a, b);
			result += cost;
		}
	}

	cout << result << '\n';
	return 0;
}