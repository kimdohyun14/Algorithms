#include <iostream>
#include <algorithm>
#define MAX_SIZE 51
using namespace std;

char mp[MAX_SIZE][MAX_SIZE]; 
int total;

void swapRow(int x, int y) {
	char temp = mp[x][y];
	mp[x][y] = mp[x][y + 1];
	mp[x][y + 1] = temp;
}

void swapCol(int x, int y) {
	char temp = mp[x][y];
	mp[x][y] = mp[x + 1][y];
	mp[x + 1][y] = temp;
}

void candyCount(int size) {
	int cnt;
	//���� ���鼭 ī��Ʈ
	for (int row = 0; row < size; row++) {
		cnt = 1;
		for (int col = 1; col < size; col++) {
			if (mp[row][col - 1] == mp[row][col]) { //���� ���� �� ������ ī��Ʈ ����
				cnt++;
			}
			else { //���࿡ �ٸ��ٸ� �ٽ� �� �������κ��� ī��Ʈ ����
				total = max(total, cnt);
				cnt = 1;
			}
		}
		total = max(total, cnt);
	}

	//���� ���鼭 ī��Ʈ
	for (int row = 0; row < size; row++) {
		cnt = 1;
		for (int col = 1; col < size; col++) {
			if (mp[col - 1][row] == mp[col][row]) {
				cnt++;
			}
			else {
				total = max(total, cnt);
				cnt = 1;
			}
		}
		total = max(total, cnt);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swapRow(i, j); //�� ����
			candyCount(n);
			swapRow(i, j);

			swapCol(i, j); //�� ����
			candyCount(n);
			swapCol(i, j);
		}
	}

	cout << total;
	return 0;
}