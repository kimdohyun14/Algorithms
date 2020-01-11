#include <iostream>
#include <cmath>
using namespace std;

// ���� ��ũ : https://m.blog.naver.com/PostView.nhn?blogId=puri8467&logNo=221440092130&proxyReferer=https%3A%2F%2Fwww.google.com%2F

// from ������ ��ġ, by�� ���İ��� ��ġ, to�� ���� ��ġ
// n�� �Űܾ��ϴ� ������ ����
// ��ͷ� �����ϸ�
void HanoiTower(int from, int by, int to, int n) {
	// �Űܾ��ϴ� ������ ������ 0�̸� �� �ű���̹Ƿ� (���� ����)
	if (n == 0) return;

	// n���� ������ ���� ��, n-1���� ������ 1 -> 2 �̵�
	HanoiTower(from, to, by, n - 1);
	// ���� �ؿ��ִ� 1���� ������ 1 -> 3 �̵�
	cout << from << " " << to << '\n';
	// n-1���� ������ 2 -> 3 �̵�
	HanoiTower(by, from, to, n - 1);
}



int main() {
	int k;
	cin >> k;
	// N ���� ž�� �ű�� ���ؼ��� �ּ��� ���?
	// ���� ū N+1�� ������ �ű�� ���ؼ��� N���� ������ �ٸ� ������ �ű��.
	// N���� ������ 1 -> 2�� �ű�� ���� F(n)���̶�� �ϸ�,
	// N+1�� ������ 1 -> 3�� �ű�� ���� 1���̴�.
	// N���� ������ 2 -> 3�� �ű�� ���� F(n)���̴�.

	// ���� ������ ���� ��ȭ���� ���� �� �ִ�.
	// F(n+1) = 2 * F(n) + 1
	// F(n)�� �Ϲ����� ���ϱ� ���ؼ��� ���� ������ �̿��ؼ� �ذ��Ѵ�.
	// An = A1(ù°��) + (1 ~ N - 1)������ �������� ���� �̿��Ѵ�.
	// F(n) = 2^N - 1

	cout << ((int)pow(2.0, (float)k)) - 1 << '\n';
	HanoiTower(1, 2, 3, k);
	return 0;
}