#include <iostream>
#include <stack>
#include <string>
using namespace std;

// vps �Ǻ���
// stack�� ����ְ� ) �� ������ false
// stack�� ����ְ� ( �� ������ push
// stack�� ������� �ʴٸ�,
// top�� (�̰�, )�̸� pop (�̸� push
// ���� ��, ������ ������� �ʴٸ� false

// �ٸ� ���
// ���� ��ȣ��� push
// �ݴ� ��ȣ���
// ������ ������� ������, ¦�� ������ pop �ٸ��ٸ� false
// ������ ����ִٸ� false

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;

		stack<char> st;
		bool ok = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (st.empty())
			{
				if (s[i] == ')')
				{
					ok = false;
					break;
				}
				st.push(s[i]);
			}
			else
			{
				if (st.top() == '(' && s[i] == ')')
					st.pop();
				else if (st.top() == '(' && s[i] == '(')
					st.push(s[i]);
				else
				{
					ok = false;
					break;
				}
			}
		}

		if (!st.empty()) ok = false;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}