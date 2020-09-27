#include <bits/stdc++.h>
using namespace std;

// �� ������ �湮�ߴ��� ���θ� �Ǵ�
bool visited[9];
// �׷����� ��������Ʈ : �ð� ���⵵ O(V + E)
vector<int> graph[9];

// DFS �Լ� ����
void DFS(int x) {
	// ���� ��带 �湮 ó��
	visited[x] = true;
	cout << x << ' ';
	// ���� ���� ����� �ٸ� ��带 ��������� �湮
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		// ���� �湮�� �� ���ٸ� �湮
		if (!visited[y]) DFS(y);
	}
	// ���̻� �湮�� ������ ������, ��� ȣ���� �����ϰ� ���� �������� ���ư���.
}

int main() {
	// ��� 1�� ����� ��� ���� ����
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	// ��� 2�� ����� ��� ���� ����
	graph[2].push_back(1);
	graph[2].push_back(7);

	// ��� 3�� ����� ��� ���� ����
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	// ��� 4�� ����� ��� ���� ����
	graph[4].push_back(3);
	graph[4].push_back(5);

	// ��� 5�� ����� ��� ���� ����
	graph[5].push_back(3);
	graph[5].push_back(4);

	// ��� 6�� ����� ��� ���� ����
	graph[6].push_back(7);

	// ��� 7�� ����� ��� ���� ����
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	// ��� 8�� ����� ��� ���� ����
	graph[8].push_back(1);
	graph[8].push_back(7);

	// �������� ������ N���� ��� O(N)�� �ð��� �ҿ�ȴ�.
	DFS(1);
	return 0;
}