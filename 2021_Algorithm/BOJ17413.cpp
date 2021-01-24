#include <iostream>
#include <stack>
#include <string>
using namespace std;

// �±��� �� ('<' , '>' ����) �׳� ���
// �±װ� �ƴ� ��, stack�� �ְ� �±׸� ���� �� stack���� ������.

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);
	s += '\n';
	stack<char> st;
	bool isTag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '<')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << s[i];
			isTag = true;
		}
		else if (s[i] == '>')
		{
			cout << s[i];
			isTag = false;
		}
		else if (isTag) // �±� ���� ��� �׳� ���
			cout << s[i];
		else if (s[i] == ' ' || s[i] == '\n')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << s[i];
		}
		else st.push(s[i]);
	}
	return 0;
}