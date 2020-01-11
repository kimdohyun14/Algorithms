#include <iostream>
#define MAX_SIZE 2190
using namespace std;

int mp[MAX_SIZE][MAX_SIZE];
int minusOneCnt, zeroCnt, oneCnt;

//�� ���� ī��Ʈ�� ��������
bool check(int x, int y, int size) {
	int target = mp[x][y];
	for (int i = x; i < x + size; i++) { //�� ��ǥ�� ���� �����ŭ Ž��
		for (int j = y; j < y + size; j++) {
			if (target != mp[i][j]) return false;//���̰� �ϳ��� �ٸ��ٸ�
		}
	}
	return true;
}

//���� Ŀ��
void cutting(int x, int y, int size) {
	if (check(x, y, size) == true) {
		if (mp[x][y] == -1) minusOneCnt++;
		else if (mp[x][y] == 0) zeroCnt++;
		else oneCnt++;
		return;
	}
	else { //�� ���� ���̸� ī��Ʈ �������� ���̸� ����
		int newSize = size / 3;
		for (int i = 0; i < 3; i++) { //�� ��ǥ�� ���� �����ŭ Ž��
			for (int j = 0; j < 3; j++) {
				cutting(x + i * newSize, y + j * newSize, newSize); //���
			}
		}
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { //�Է�
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	cutting(0, 0, n); //���� Ŀ��

	cout << minusOneCnt << '\n';
	cout << zeroCnt << '\n';
	cout << oneCnt << '\n';
	return 0;
}