#include <bits/stdc++.h>
using namespace std;

string str;
int count0 = 0; // ���� 0���� �ٲٴ� ���
int count1 = 0; // ���� 1�� �ٲٴ� ���

int main() {
	cin >> str;

	// ù ��° ���ҿ� ���ؼ� ó��
	if (str[0] == '1') {
		count0 += 1;
	}
	else {
		count1 += 1;
	}

	// �� ��° ���Һ��� ��� ���Ҹ� Ȯ���ϸ�
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] != str[i + 1]) {
			// ���� ������ 1�� �ٲ�� ���
			if (str[i + 1] == '1') count0 += 1;
			// ���� ������ 0���� �ٲ�� ���
			else count1 += 1;
		}
	}

	cout << min(count0, count1) << '\n';
	return 0;
}