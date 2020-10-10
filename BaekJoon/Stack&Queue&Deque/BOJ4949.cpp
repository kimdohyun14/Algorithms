#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		string a;
		getline(cin, a);
		if (a == ".") break;
		stack<char> s;
		bool ok = true;
		for (auto c : a) {
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')') {
				// s.empty() ���� Ȯ�����ָ�, runtime ���� ���� �� Short-circuit evaluation �Ǵ��� ����
				if (s.empty() || s.top() != '(') { 
					ok = false;
					break;
				}
				s.pop();
			}
			else if (c == ']') {
				if (s.empty() || s.top() != '[') {
					ok = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) ok = false;
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}