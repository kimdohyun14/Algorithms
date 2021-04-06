#include <iostream>
#include <string>
using namespace std;

// ù ��° ���ڷ� '_'�� �빮��
// '_'�� �������� ������ ���
// '_' ������ �빮��
// c++ ��� �ν��ߴ´� �빮�ڰ� ������
// java ��� �ν��ߴ´�  '_' �� ������ ���
// ������ ���ڰ� '_'�� ���

int main()
{
	string s;
	cin >> s;

	bool cpp = false, java = false, err = false;
	string ret;
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			if (i == 0 || cpp)
			{
				err = true;
				break;
			}
			ret += '_';
			ret += tolower(s[i]);
			java = true;
		}
		else if (s[i] == '_')
		{
			if (!i || java || i == s.length() - 1 ||
				s[i + 1] == '_' || isupper(s[i + 1]))
			{
				err = true;
				break;
			}
			ret += toupper(s[i + 1]);
			i++;
			cpp = true;
		}
		else
			ret += s[i];
	}

	if (err)
		cout << "Error!\n";
	else
		cout << ret << '\n';

	return 0;
}