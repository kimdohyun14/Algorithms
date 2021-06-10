#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char maze[9][9];
char wallBoard[9][9][9];
bool vis[9][9][9];

vector<pair<int, int>> wall;

int dx[] = { -1,-1,-1,0,0,1,1,1,0 };
int dy[] = { -1,0,1,-1,1,-1,0,1,0 };

struct State {
	int x, y, t;
};

bool isValid(int x, int t) {
	for (int i = x - 1; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (wallBoard[t][i][j] == '#') return false;
		}
	}
	return true;
}

int bfs() {
	queue<State> q;
	q.push({ 7,0,0 });
	while (!q.empty()) {
		State cur = q.front();
		q.pop();

		//���� 0���� �Դٸ�, �ᱹ ����� �� �ִٴ� �Ҹ� (���� ��� ������)
		if (cur.x == 0) 
			return 1;
		//(x,t) ���� �� ���� ���� ���ٸ� �ᱹ ����� �� �ִٴ� �Ҹ�
		else if (isValid(cur.x, cur.t)) 
			return 1;

		for (int i = 0; i < 9; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nt = cur.t + 1;

			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
			//���� �ð����� ���� ������ ��ǥ�� �ʰ�, ���� �ð����� ���� ������ ��ǥ�� �� ��� '.'����
			if (wallBoard[nt][nx][ny] == '.' && wallBoard[cur.t][nx][ny] == '.') {
				q.push({ nx,ny,nt });
			}
		}
	}
	return 0; //����
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '#') {
				wallBoard[0][i][j] = '#'; // 0�� (i, j) ��
				wall.push_back({ i,j });
			}
		}
	}

	for (int t = 0; t < 8; t++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (wallBoard[t][i][j] == '#') continue;
				wallBoard[t][i][j] = '.';
			}
		}
	}

	//���ʿ� ���� ������ ������ �� �� �ִ�.
	if (wall.size() == 0) {
		cout << 1 << '\n';
		return 0;
	}

	//������ �����ϰ� ä�����ִٸ� �Ұ���.
	bool ok = true;
	for (int i = 0; i < 7; i++) {
		int cnt = 0;
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == '#') cnt++;
		}
		if (cnt == 8) {
			ok = false;
			break;
		}
	}

	if (!ok) {
		cout << 0 << '\n';
		return 0;
	}

	//�ð��� ���� �� �̵� �� ��ȭ ����
	for (int i = 0; i < wall.size(); i++) {
		int x = wall[i].first;
		int y = wall[i].second;
		int t = 1;

		while (true) {
			int nx = x + 1;
			int ny = y;
			if (nx >= 8) break;

			wallBoard[t][nx][ny] = '#';
			t++;
			x = nx;
			y = ny;
		}
	}

	cout << bfs() << '\n';
	return 0;
}