#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	string ret;
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			ret += s[i];
		else
		{
			if (s[i] == '(')
				st.push(s[i]);
			// ���� �����ں��� �켱������ ���ų� ���� �����ڵ��� ���� ����� ����Ѵ�.
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!st.empty() && (st.top() == '*' || st.top() == '/'))
				{
					ret += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!st.empty() && st.top() != '(')
				{
					ret += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!st.empty() && st.top() != '(')
				{
					ret += st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}

	while (!st.empty())
	{
		ret += st.top();
		st.pop();
	}

	cout << ret << '\n';
	return 0;
}