#include <iostream>
using namespace std;

int zoo[100001][3];
//zoo[i][j] : iĭ�� j��°�� ���ڸ� ��ġ�ϴ� ����� ��
//zoo[i][0] : ���ڸ� ��ġ���� �ʾ��� ��
//zoo[i][1] : ���ڸ� ���ʿ� ��ġ
//zoo[i][2] : ���ڸ� �����ʿ� ��ġ

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	//ó���� ��ġ�ϴ� ����� ����
	//���ڸ� ��ġ���� �ʰų�, ���ʿ� ��ġ Ȥ�� �����ʿ� ��ġ�ϴ� ���� 1����
	zoo[1][0] = zoo[1][1] = zoo[1][2] = 1;

	//���ĺ��ʹ� ����ؼ� �����Ѵ�.
	for (int i = 2; i <= n; ++i) {
		zoo[i][0] = (zoo[i - 1][0] + zoo[i - 1][1] + zoo[i - 1][2]) % 9901;
		zoo[i][1] = (zoo[i - 1][0] + zoo[i - 1][2]) % 9901;
		zoo[i][2] = (zoo[i - 1][0] + zoo[i - 1][1]) % 9901;
	}

	int ans = (zoo[n][0] + zoo[n][1] + zoo[n][2]) % 9901;
	cout << ans;
	return 0;
}