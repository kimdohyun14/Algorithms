#include <iostream>
#include <string>
using namespace std;

/*
	# std::string::find �Լ� ����
	size_t find(const string& str, size_t pos = 0) const noexcept;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_type n) const;
	size_t find(char c, size_t pos = 0) const noexcept;

	#parameter
	str : �˻� ���ڿ�
	pos : �˻����� ����� ���ڿ��� ù ��° ���� ��ġ
	s : ���� �迭�� ���� ������
	n : ��ġ��ų ���� �������� ����
	c : �˻� ����

*/

string replaceAll(string& str, const string& from, const string& to)
{
	size_t start = 0;
	while ((start = str.find(from, start)) != string::npos)
	{
		str.replace(start, from.length(), to);
		start += to.length();
	}
	return str;
}

int main()
{
	string str = "There are two needles in this haystack with needles.";
	string str2 = "needles";

	// size_t : ��ȣ���� ���� ����
	size_t found = str.find(str2);
	if (found != string::npos)
	{
		cout << "first 'needle' found ad: " << found << '\n';
	}

	// 3��° �ε����� ��ġ��ų ���� �������� ����
	found = str.find("needles are small", found + 1, 7);
	if (found != string::npos)
	{
		cout << "second 'needles' found at: " << found << '\n';
	}

	found = str.find("haystack");
	if (found != string::npos)
	{
		cout << "'haystack' also found at: " << found << '\n';
	}

	found = str.find('.');
	if (found != string::npos)
	{
		cout << "Period found at: " << found << '\n';
	}

	string str3 = str;
	str3.replace(str3.find(str2), str2.length(), "preposition");
	cout << str3 << '\n';

	string str4 = str;
	str4 = replaceAll(str4, str2, "preposition");
	cout << str4 << '\n';
	return 0;
}