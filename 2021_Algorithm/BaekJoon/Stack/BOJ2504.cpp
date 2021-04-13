#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

// ��ȣ�� ���� ���빰�� �ֳ� ���Ĵ� �߿����� �ʴٴ� ��
string s;
stack<char> st;
long long ret;
int main()
{
	cin >> s;
	int sum = 1;
	bool ok = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			sum *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[')
		{
			sum *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')' && (st.empty() || st.top() != '('))
		{
			ok = false;
		    break;
		}
		else if (s[i] == ']' && (st.empty() || st.top() != '['))
		{
			ok = false;
			break;
		}
		else if (s[i] == ')')
		{
			if (s[i - 1] == '(')
				ret += sum;
			st.pop();
			sum /= 2;
		}
		else if (s[i] == ']')
		{
			if (s[i - 1] == '[')
				ret += sum;
			st.pop();
			sum /= 3;
		}
	}

	if (!ok || !st.empty())
		cout << 0 << '\n';
	else
		cout << ret << '\n';
	return 0;
}