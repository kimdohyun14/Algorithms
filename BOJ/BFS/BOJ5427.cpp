#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

#define SIZE 1000
using namespace std;

char map[SIZE][SIZE];    //���� ����
int visit[SIZE][SIZE];   //�湮 ǥ��
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int h, w;

//�� ǥ��
void show(int time);
//bfsŽ��
int mission(queue<pair<int, int>>& fires, int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	for (int testCase = 0; testCase < t; ++testCase) {
		cin >> w >> h;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		queue<pair<int, int>> fires; //���� ��ġ ����
		int sx = 0, sy = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> map[i][j];

				if (map[i][j] == '*') {
					fires.push(make_pair(i, j));
					visit[i][j] = 2; //���̶�� ǥ��
				}
				else if (map[i][j] == '@') {
					sx = i, sy = j;
					visit[i][j] = 1; //����̶�� ǥ��
				}
			}
		}
		//���� ��ġ, ������� ������� ���� �̼��� �Ѵ�.
		int res = mission(fires, sx, sy);
		if (res > 0) { //Ż���Ѵٸ� �� �ʿ� Ż�� �ߴ���
			cout << res << '\n';
		}
		else { //Ż���� ���� �������� �Ұ��� ǥ��
			cout << "IMPOSSIBLE" << '\n';
		}
	}
	return 0;
}

void show(int time) {
	cout << time << "����" << endl;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int mission(queue<pair<int, int>>& fires, int x, int y) {

	queue<pair<int, int>> human;
	human.push(make_pair(x, y));
	int time = 0;

	while (!human.empty()) {
		++time; // 1�� ��

		//����� �̵�
		int size = human.size();
		for (int i = 0; i < size; ++i) {
			int cx = human.front().first;
			int cy = human.front().second;
			human.pop();

			//���� ��ġ�� ���࿡ ���̶�� ����̴� �� �� ���� ���̴�.
			if (map[cx][cy] == '*') continue;

			//��� �̵�
			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				//Ż�ⱸ�� ��� ���� ����� Ż���ߴٰ� �� �� �ִ�.
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					return time;
				}
				//����̰� �� �� �ִ� ��δ� �� �����̸�, �湮���� �ʾ��� ��
				if (map[nx][ny] == '.' && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					human.push(make_pair(nx, ny));
				}
			}
		}

		//���� �̵��� �ؾ��Ѵ�.
		int cycle = fires.size();

		for (int i = 0; i < cycle; ++i) {
			int cx = fires.front().first;
			int cy = fires.front().second;
			fires.pop();

			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				//��� üũ
				if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
					//���� �̵��� ������̸� �̵��Ѵ�.
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						visit[nx][ny] = 2;
						fires.push(make_pair(nx, ny));
					}
				}
			}
		}
		//show(time);
		//cout << '\n';
	}
	return 0;
}