#include <bits/stdc++.h>
using namespace std;

/*
	���� ��ȣ�� ������ push
	�ݴ� ��ȣ�� ������ ������ ����غ���.
	������ ����ִٸ� �߸��� ���ڿ�,
	������ ������� �ʴٸ� ������ ����Ѵ�.
	������ ������� ������ ������ ����Ⱑ ���� ��ȣ��� pop,
	������ ������� ������ ������ ����Ⱑ ���� ��ȣ�� �ƴ϶�� �߸��� ���ڿ�

	��� ������ ���� �� ���ÿ� ���ڿ��� �����ִٸ� �� ���� �߸��� ���ڿ��̴�.
*/

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string query;
		cin >> query;
		stack<int> st;
		for (auto c : query) {
			if (c == '(') st.push(c);
			else { // �ݴ� ��ȣ�� ���
				if (st.empty()) {
					st.push('x'); // stack�� ������ ���� ä������ Ż��
					break;
				}

				if (c == ')') {
					if (st.top() != '(') break;
				}
				st.pop();
			}
		} // end query

		if (st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}