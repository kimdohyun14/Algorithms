#include <iostream>
#include <vector>
using namespace std;

vector<int> a[20001];
int check[200001];

// �湮���� �ʾ����� 0
// �׷� A�� 1�� ��ĥ
// �׷� B�� 2�� ��ĥ
void dfs(int node, int color) {
	check[node] = color;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == 0) {
			dfs(next, 3 - color);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		// �ʱ�ȭ
		for (int i = 1; i <= v; i++) {
			a[i].clear();
			check[i] = 0;
		}
		// �׷��� ����ǥ��
		for (int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		// ��ĥ�ϱ�
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}

		// �� �׷����� �̺б׷������� Ȯ��
		// ���� a���� ���� ������ a�� ���� �޶���Ѵ�.
		// ���࿡ ������ �� �׷����� �̺б׷����� �ƴϴ�.
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next_node = a[i][j];
				if (check[i] == check[next_node]) {
					ok = false;
				}
			}
		}

		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}