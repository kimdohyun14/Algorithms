#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	bool flag = true; // �ܾ��� ������ �빮�ڷ� �����Ѵ�.
	                  // �빮�� -> �ҹ��� -> �빮��...

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			answer += ' ';
			flag = true;
		}

		else
		{
			if (flag)
			{
				flag = false;
				answer += toupper(s[i]); // �빮�ڷ� �ٲ��ֱ�
			}

			else
			{
				flag = true;
				answer += tolower(s[i]); // �ҹ��ڷ� �ٲ��ֱ�
			}
		}
	}
	return answer;
}