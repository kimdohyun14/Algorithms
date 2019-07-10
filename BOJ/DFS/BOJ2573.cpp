#include <iostream>
#define MAX_SIZE 301
using namespace std;

int iceBerg[MAX_SIZE][MAX_SIZE];
int copyIceBerg[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

//���� Ž��
void dfs(int x, int y, int row, int col) {
	visit[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (visit[nx][ny] == true) continue;
		if (nx < 0 || nx >= row) continue;
		if (ny < 0 || ny >= col) continue;
		if(iceBerg[nx][ny] > 0)
			dfs(nx, ny, row, col);
	}
}

bool solve(int row, int col) {
	int iceBergCnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (iceBerg[i][j] > 0 && visit[i][j] == false) {
				iceBergCnt++; //���� �� ����
				dfs(i, j, row, col);
			}
			if (iceBergCnt >= 2) return true; //������ 2���� �̻��̸�
		}
	}
	return false;
}

//���� ���̱�
void melt(int row, int col) {
	int waterCnt = 0; //�������ִ� �ٴ幰�� ��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (iceBerg[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) { //�����¿� Ȯ���ؼ� �ٴ幰�̸�
					int ni = i + dx[dir];
					int nj = j + dy[dir];
					if (ni < 0 || ni >= row) continue;
					if (nj < 0 || nj >= col) continue;
					if (iceBerg[ni][nj] == 0) waterCnt++;
				}
				if (iceBerg[i][j] >= waterCnt) { //������ ������ �ٴ幰��ŭ ��´�.
					copyIceBerg[i][j] -= waterCnt;
					waterCnt = 0;
				}
				else {
					copyIceBerg[i][j] = 0;
					waterCnt = 0;
				}
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			iceBerg[i][j] = copyIceBerg[i][j];
		}
	}
}

//������ �����ִ���
bool iceCheck(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (iceBerg[i][j] > 0)
				return true;
		}
	}
	return false;
}

//�湮 �ʱ�ȭ
void visitInit(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visit[i][j] = false;
		}
	}
}

void showMap(int row, int col) {
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << iceBerg[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> iceBerg[i][j];
			copyIceBerg[i][j] = iceBerg[i][j];
		}
	}
	int ans = 0;
	bool ret = false;
	while (iceCheck(N, M)) {
		ans++; //1����
		visitInit(N, M); //�ʱ�ȭ
		melt(N, M); //���� ���̱�
		ret = solve(N, M);
		//showMap(N, M);
		if (ret == true) break;
	}

	if (ret == false) {
		cout << 0;
		return 0;
	}
	else {
		cout << ans;
	}
	return 0;
}