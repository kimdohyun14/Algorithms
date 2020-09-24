#include <bits/stdc++.h>
using namespace std;

// 2���� ����Ʈ 90�� ȸ���ϱ�
vector<vector<int> > rotate(vector<vector<int> > a) {
	int n = a.size();    // �� ���� ���
	int m = a[0].size(); // �� ���� ���
	vector<vector<int> > result(n, vector<int>(m)); // ��� ����Ʈ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][n - 1 - i] = a[i][j];
		}
	}
	return result;
}

// �ڹ����� �߰� �κ��� ��� 1���� Ȯ��
bool check(vector<vector<int> > newlock) {
	int lock_length = newlock.size() / 3;
	for (int i = lock_length; i < lock_length * 2; i++) {
		for (int j = lock_length; j < lock_length * 2; j++) {
			if (newlock[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
	int n = lock.size();
	int m = key.size();
	// �ڹ����� ũ�⸦ ������ 3��� ��ȯ
	vector<vector<int> > newlock(n * 3, vector<int>(n * 3));
	// ���ο� �ڹ����� �߾� �κп� ������ �ڹ��� �ֱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			newlock[i + n][j + n] = lock[i][j];
		}
	}

	// 4���� ���⿡ ���ؼ� Ȯ��
	for (int rotation = 0; rotation < 4; rotation++) {
		key = rotate(key); // ���� ȸ��
		for (int x = 1; x < n * 2; x++) {
			for (int y = 1; y < n * 2; y++) {
				// ���� �� 3 x 3 ���¿��� Ȯ���ϸ�,
				// ���� 2�� ������ ���� ������ ��� �� �� (1,1) ~ (5,5) ���� ������
				// �� ��ġ���� ���踦 ���� �־ �ڹ��踦 Ǯ �� �ִ��� Ȯ���Ѵ�.
				// ���� �����ؼ� �ڹ��迡 ���踦 �̸����� �־��.
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) { 
						newlock[x + i][y + j] += key[i][j];
					}
				}
				// ���ο� �ڹ��迡 ���谡 ��Ȯ�� ��� �´��� �˻�
				if (check(newlock)) return true;
				// �ڹ��迡�� ���踦 �ٽ� ����
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						newlock[x + i][y + j] -= key[i][j];
					}
				}
			}
		}
	}
	return false;
}