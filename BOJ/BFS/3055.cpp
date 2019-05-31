#include <iostream>
#include <queue>
using namespace std;

int pathMap[51][51];     //����ġ �̵����
int waterMap[51][51];    //���� �̵����
int visited[51][51];     //����ġ �湮���
char originMap[51][51];  //����
int dx[] = { 0,0,-1,1 }; //����
int dy[] = { 1,-1,0,0 };
int R, C;                //���
int start_x, start_y;    //����ġ ���۰��
int end_x, end_y;        //���� �������
bool check = false;      //���� ��������
queue<pair<int, int>> water; //�� ������ġ ����

void waterBfs()
{
	while (!water.empty()) {
		int cx = water.front().first;
		int cy = water.front().second;
		water.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				/* ��ΰ� ����ִ� ���̸� */
				if (originMap[nx][ny] == '.' && originMap[nx][ny] != 'D') {
					if (waterMap[nx][ny] == 0) {
						/* �� ��θ� ī���͸� �÷��� ���� ä���. */
						waterMap[nx][ny] = waterMap[cx][cy] + 1; //ī���� �÷��ֱ�
						water.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void HedgehogBfs(int start_x, int start_y)
{
	queue<pair<int, int>> hog;
	hog.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = 1;
	while (!hog.empty()) {
		int cx = hog.front().first;
		int cy = hog.front().second;
		hog.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (originMap[nx][ny] == '.' || originMap[nx][ny] == 'D') {
					/* �̵��Ϸ��� ��ΰ� ���� ���� ���̸�, �湮���� �ʾҴٸ� */
					if (pathMap[nx][ny] == 0 && waterMap[nx][ny] == 0 && visited[nx][ny] == 0) {
						pathMap[nx][ny] = pathMap[cx][cy] + 1;
						visited[nx][ny] = 1;
						hog.push(make_pair(nx, ny));
					}
					/* ���� ������ �ӵ��� ����ġ�� �̵��� �ӵ����� ũ�ٸ� ���ÿ� �湮���� �ʾҴٸ�
					���� ������ ���� ����ġ�� �̵��� �� �ֱ� ������ */
					else if ((waterMap[nx][ny] > pathMap[cx][cy] + 1) && visited[nx][ny] == 0) {
						pathMap[nx][ny] = pathMap[cx][cy] + 1;
						visited[nx][ny] = 1;
						hog.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void printWaterMap()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << waterMap[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void printPathMap()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << pathMap[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> originMap[i][j];
			/* ����ġ ���� ��� ���� */
			if (originMap[i][j] == 'S') {
				start_x = i; start_y = j;
			}
			/* ���� ���� ��� ���� */
			if (originMap[i][j] == '*') {
				water.push(make_pair(i, j));
			}
			/* ������ ���� ��� ���� */
			if (originMap[i][j] == 'D') {
				end_x = i; end_y = j;
			}
		}
	}
	/* �� �̵� BFS */
	waterBfs();
	//printWaterMap();
	/* ����ġ �̵� BFS */
	HedgehogBfs(start_x, start_y);
	//printPathMap();

	int ans = 0;
	/* ����ġ�� �������� �� �Ÿ� ���� */
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			/* ����ġ�� ������ ���� ���ߴٸ� */
			if (end_x == i && end_y == j) {
				if (pathMap[i][j] == 0) {
					check = false;
				}
				else {
					ans = pathMap[i][j];
					check = true;
				}
			}
		}
	}
	/* ������ �����ߴٸ� ���� ����ϰ�, �ƴϸ� ���� ��� */
	if (check == false) {
		cout << "KAKTUS";
		return 0;
	}
	else {
		cout << ans;
	}

	return 0;
}