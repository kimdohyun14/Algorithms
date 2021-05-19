#include <iostream>
#include <vector>
using namespace std;

int n, answer;
int col[16]; // 1 ~ 15

// 1�� ~ row-1����� ���� �� Ȥ�� �밢���� ��ġ�ϴ� ���� �ִ��� Ȯ���Ѵ�.
bool Promising(int row) {
	for (int i = 1; i < row; ++i) {
		// i��� row���� �� ���� ������ ���� ���� �� ����.
		if (col[i] == col[row])
			return false;

		// i��� row���� �� ���� �밢���� ��ġ�ϴ� ���밪�̸� �ȵȴ�.
		if (abs(i - row) == abs(col[i] - col[row]))
			return false;
	}

	return true;
}

// row������� ���� ���� ����
// row+1�࿡ ���� ���� �� �ִ��� ������ Ȯ��
// ���� row ���� n�� ���ٸ� ��� �࿡ ���� ���Ҵٴ� ���̹Ƿ� answer + 1
void DFS(int row) {
	if (row == n) {
		++answer;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		col[row + 1] = i; // row+1�� i���� �д�.
		if (Promising(row + 1)) {
			DFS(row + 1);
		}
		col[row + 1] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	// �� 1�࿡ 1�� ~ n������ ���鼭 ���� ������ �� ������ ���θ� Ȯ���Ѵ�.
	for (int i = 1; i <= n; ++i) {
		// 1�� i���� ���� ���Ҵ�.
		col[1] = i;
		// 1�� i���� ���� ������ ��� ������ Ƚ���� ���Ѵ�.
		DFS(1);
	}


	cout << answer;
	return 0;
}