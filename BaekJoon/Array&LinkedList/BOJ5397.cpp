#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;

		// insert, erase�� �ϸ� iterator�� ��ġ�� �޶�����.
		list<char> password;
		auto cursor = password.end();
		for (auto c : str) {
			if (c == '<') {
				if (cursor != password.begin())
					cursor--;
			}
			else if (c == '>') {
				if (cursor != password.end())
					cursor++;
			}
			else if (c == '-') {
				if (cursor != password.begin()) {
					cursor--;
					// erase�� ���� ���Ҹ� ����Ų��.
					cursor = password.erase(cursor);
				}
			}
			else {
				// insert�� ���� ��ġ�� �״�� ������
				password.insert(cursor, c);
			}
		}
		for (auto c : password) cout << c;
		cout << '\n';
	}
	return 0;
}