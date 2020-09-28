#include <bits/stdc++.h>
using namespace std;

class Virus {
public:
	int index;
	int second;
	int x;
	int y;
	Virus(int index, int second, int x, int y)
		:index(index), second(second), x(x),y(y) { }
	// ���� ������ '��ȣ�� ���� ����'
	bool operator<(Virus& other) {
		return this->index < other.index;
	}
};

int n, k;
int graph[200][200];
vector<Virus> viruses;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] != 0) {
				// {���̷��� ����, �ð�, x, y}
				viruses.push_back(Virus(graph[i][j], 0, i, j));
			}
		}
	}

	// ���� ���Ŀ� ť�� �ű�� (���� ��ȣ�� ���̷����� ���� �����ϹǷ�)
	sort(viruses.begin(), viruses.end());
	queue<Virus> q;
	for (int i = 0; i < viruses.size(); i++) {
		q.push(viruses[i]);
	}

	int target_s, target_x, target_y;
	cin >> target_s >> target_x >> target_y;

	// BFS ����
	while (!q.empty()) {
		Virus virus = q.front();
		q.pop();
		// ��Ȯ�� second��ŭ �ʰ� �����ų�, ť�� �� ������ �ݺ�
		if (virus.second == target_s) break;
		// ���� ��忡�� �ֺ� 4���� ��ġ�� ���� Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = virus.x + dx[i];
			int ny = virus.y + dy[i];
			// �ش� ��ġ�� �̵��� �� �ִ� ���
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// ���� �湮���� ���� ��ġ���, �� ��ġ�� ���̷��� �ֱ�
				if (graph[nx][ny] == 0) {
					graph[nx][ny] = virus.index;
					q.push(Virus(virus.index, virus.second + 1, nx, ny));
				}
			}
		}
	}

	cout << graph[target_x - 1][target_y - 1] << '\n';
	return 0;
}