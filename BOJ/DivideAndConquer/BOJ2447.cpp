#include <iostream>
#include <cstring>
using namespace std;
//0, 3, 6, 9, 12, 15, 18, 21, 24

// ��Ģ�� ������ ����.
/*

	3 * 3
	***
	* *
	***

	9 * 9
	*********
	* ** ** *
	*********
	***   ***
	* *   * *
	***   ***
	*********
	* ** ** *
	*********

	3 * 3�� ��쿡 8���� �� �ٿ��ָ� 9 * 9 ���ȴ�.
	27 * 27�� ���� 9 * 9�� 8���� �� �ٿ��ָ� 27 * 27 �� �ȴ�.
	... ���� �ݺ�
*/

/*
// 1��° Ǯ�� (���� ���� Ǯ��)
// ���� ��ũ : https://m.blog.naver.com/PostView.nhn?blogId=moonsoo5522&logNo=220706431458&proxyReferer=https%3A%2F%2Fwww.google.com%2F

char mat[2201][2201];

void solve(int x, int y, int num) {
	if (num == 1) { // �� ĭ�̸� ���� ��ĥ�Ѵ�
		mat[x][y] = '*';
		return;
	}

	// 27 * 27 => 9 * 9 => 3 * 3 => 1 * 1
	int div = num / 3;
	// ���� 9���ҷ� ������.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			else // �ϳ��� ���� �ٽ� ���� 9���� �����Ѵ�.
				solve(x + (i * div), y + (j * div), div);
		}
	}
}

int main() {
	int n;
	cin >> n;

	memset(mat, ' ', sizeof(mat));

	solve(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
	return 0;
}

*/

// 2��° Ǯ�� (���� ����)
// ���� ��ũ : https://blockdmask.tistory.com/231

void Draw(int dx, int dy) {
	while (dy != 0) {
		if (dx % 3 == 1 && dy % 3 == 1) {
			cout << ' ';
			return;
		}
		dx /= 3;
		dy /= 3;
	}
	cout << '*';
}

int main() {
	int n;
	cin >> n;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			Draw(x, y);
		}
		cout << '\n';
	}
	return 0;
}