#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		stack<char> s;
		string str;
		bool ok = true; // �հ� �׽�Ʈ

		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			// ���� ��ȣ�� push
			if (str[i] == '(')
			{
				s.push(str[i]);
			}
			// �ݴ� ��ȣ���?
			else
			{
				// ���ÿ� ������� ������
				if (!s.empty())
				{
					// ¦�� ������ pop
					if (s.top() == '(')
					{
						s.pop();
					}
					// ¦�� ���� �ʴٸ� Ʋ�� ��
					else
					{
						ok = false;
						break;
					}
				}
				// ���ʿ� ó������ ')'�� ���´ٸ� ���������� Ʋ�� ��
				else
				{
					ok = false;
					break;
				}
			}
		}

		// ¦�� �� ����µ�, �׷��� ������ ������� �ʴٸ�?
		if (!s.empty())
			ok = false;

		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}