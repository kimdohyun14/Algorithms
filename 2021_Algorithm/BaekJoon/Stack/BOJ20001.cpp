#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	stack<string> st;
	while (getline(cin, s))
	{
		if (s == "����")
			st.push(s);
		else if(s == "������")
		{
			if (st.empty())
			{
				st.push("����");
				st.push("����");
			}
			else
				st.pop();
		}
	}

	if (st.empty())
		cout << "�������� �����\n";
	else
		cout << "����\n";

	return 0;
}