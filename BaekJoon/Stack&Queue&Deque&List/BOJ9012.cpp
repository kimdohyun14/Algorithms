#include <iostream>
#include <stack>
#include <string>
using namespace std;

int t;

bool vps(string str) {
	stack<char> s;
	// ���� ��ȣ��� push
	// �ݴ� ��ȣ��� ������ ��� ������ false
	// ������ top�� ���� ��ȣ��� pop
	// ������ ������� �ʴٸ� false
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (s.empty() && str[i] == ')') return false;
			if (!s.empty() && s.top() == '(') s.pop();
		}
	}

	if (s.empty()) return true;
	else return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		if (vps(str)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}