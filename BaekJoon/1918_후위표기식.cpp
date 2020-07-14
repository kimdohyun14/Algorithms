// https://mygumi.tistory.com/181
// ������ �˰� Ǯ������, ������ �̼��ؼ� �ᱹ �˻��ߴ�...
// switch�� ��ٸ� �� �����ߴٴ� ���� ����.

// ���� ǥ��� -> ���� ǥ���

// �ǿ����ڴ� ���

// �������̸�
// ������ ����ְų�, top�� ���� ��ȣ, �̹� �����ڰ� ������ top�����ں��� �켱���� ������ push
// �ƴ϶��, ���� ������ ������ ������ �������� pop, �׸����� push

// ���� ��ȣ��� push

// �ݴ� ��ȣ�� ���� ��ȣ�� ���� ������ pop�ϰ�, �������� ���� ��ȣ�� pop

// ��� ó���� ���� �Ŀ� ���������� ������ �� ������ pop
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char now)
{
	switch (now)
	{
	case '*': 
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
	case ')':
		return 0;
	}
	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	string str;
	cin >> str;

	stack<char> s;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		int p = priority(str[i]);

		switch (ch)
		{
	    // �������̸�
		case '+':
		case '-':
		case '*':
		case '/':
			// ������ top�� ���� �������� �켱������ ���Ͽ�
			// ������ top�� ũ��, ����Ѵ�.
			while (!s.empty() && priority(s.top()) >= p)
			{
				cout << s.top();
				s.pop();
			}
			s.push(ch);
			break;
		case '(':
			s.push(ch);
			break;
		case ')':
			// ���� ��ȣ�� ���� ������ ã�ƺ���.
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
			break;
		default:
			// �ǿ����ڴ� ���
			cout << ch;
		}
	}

	// ��� ó���� ���� �Ŀ�, ���ÿ� �ִ� ��� �����ڵ��� pop�ϸ鼭 ���
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}