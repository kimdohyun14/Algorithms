#include <iostream>
#include <vector>
using namespace std;

// �׷����� ��������Ʈ : �ð� ���⵵ O(V + E)
vector<vector<int>> adj(7);
// �� ������ �湮�ߴ��� ���θ� �Ǵ�
vector<bool> visited;
// ���� �켱 Ž���� ����
void DFS(int here) {
	cout << "DFS visits " << here << endl;
	visited[here] = true;
	// ��� ���� ������ ��ȸ�ϸ鼭
	for (int i = 0; i < adj[here].size(); ++i) { // O(E)
		int there = adj[here][i];
		// ���� �湮�� �� ���ٸ� �湮
		if (!visited[there])
			DFS(there);
	}
	// ���̻� �湮�� ������ ������, ��� ȣ���� �����ϰ� ���� �������� ���ư���.
}

void DFSAll() {
	// visited�� ��� false�� �ʱ�ȭ
	visited = vector<bool>(adj.size(), false);
	// ��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮
	for (int i = 0; i < adj.size(); ++i)  // O(V)
		if (!visited[i])
			DFS(i);
}

int main()
{
	adj[1].push_back(2);
	adj[1].push_back(4);
	adj[2].push_back(3);
	adj[4].push_back(5);
	adj[5].push_back(6);

	DFSAll();

	return 0;
}