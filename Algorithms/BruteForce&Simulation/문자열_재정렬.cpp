#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> result;
int num = 0;

int main() {
	cin >> s;
	// ���ڸ� �ϳ��� Ȯ���ϸ鼭
	for (int i = 0; i < s.size(); i++) {
		// ���ĺ��� ��� ��� ����Ʈ�� ����
		if (isalpha(s[i])) {
			result.push_back(s[i]);
		}
		// ���ڴ� ���� ���ϱ�
		else {
			num += s[i] - '0';
		}
	}

	// ���ĺ��� ������������ ����
	sort(result.begin(), result.end());
	// ���ĺ��� ���ʴ�� ���
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	// ���ڰ� �ϳ��� �����ϴ� ��� ���� �ڿ� ���
	if (num != 0) cout << num;
	return 0;
}