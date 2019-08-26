#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string s) {

	int consonant = 0; // ������ ����
	int vowel = 0;     // ������ ����

	// �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ� �ִ�.
	int length = s.length();

	for (int i = 0; i < length; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			vowel++;
		}
		else
			consonant++;
	}

	if (vowel >= 1 && consonant >= 2)
		return true;
	else
		return false;
}

void make_password(int n, vector<char>& v, string password, int i) {
	// ������ ã�� ���
	if (n == password.length()) {
		if (check(password)) {
			cout << password << '\n';
			return;
		}
	}
	// �Ұ����� ���
	if (i >= v.size()) return;
	// ���� ���
	make_password(n, v, password + v[i], i + 1); // ���� ���ĺ��� ���
	make_password(n, v, password, i + 1);        // ���� ���ĺ��� ������� �ʴ´�.
}

int main() {
	int L, C;
	cin >> L >> C;
	vector<char> password;
	for (int i = 0; i < C; i++) {
		char ch;
		cin >> ch;
		password.push_back(ch);
	}

	sort(password.begin(), password.end());
	make_password(L, password, "", 0);
	return 0;
}