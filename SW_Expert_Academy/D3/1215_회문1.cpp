#include <iostream>
#include <string>
using namespace std;

// �ش� ��Ʈ���� ȸ������ �Ǻ����ִ� �Լ�
bool IsPalindrome(string& s)
{
	if (s.length() == 1)
		return true;
	else
	{
		for (int i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}
	}

	return true;
}

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int length; // ã�ƾ� �ϴ� ȸ���� ����
		int answer = 0;
		char a[8][8];

		cin >> length;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> a[i][j];

		// ȸ���� ã�� ����� 2������.
		// 1. �� ������ ã�ƺ���
		
		for (int i = 0; i < 8; i++) // row
		{
			for (int j = 0; j <= 8 - length; j++) // col (start����)
			{
				string str;
				for (int k = 0; k < length; k++) // ȸ���� ���� ��ŭ ��Ʈ���� �߰������ְ�
				{
					str += a[i][j + k];
				}
				
				if (IsPalindrome(str))
				{
					//cout << "�� ���� : " << str << endl;
					answer++;
				}
				
			}
		}
		
		
		// 2. �� ������ ã�ƺ���
		for (int i = 0; i < 8; i++) // col
		{
			for (int j = 0; j <= 8 - length; j++) // row
			{
				string str;
				for (int k = 0; k < length; k++)
				{
					str += a[j + k][i];
				}
				

				if (IsPalindrome(str))
				{
					//cout << "�� ���� : " << str << endl;
					answer++;
				}
				
			}
		}
		
		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}