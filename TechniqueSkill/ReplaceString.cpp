#include <iostream>
#include <string>
#include <algorithm> // replace()
using namespace std;

/*
	# replace
	
	# �Լ� ����
	string& replace(size_t index, size_t len, const string& str)
	index ��ġ���� len ���̱����� ������ �Ű������� ���� str ��ü�� ��ü�Ѵ�.
*/

// string::find() ���
string replaceAll(string& str, const string& from, const string& to)
{
	size_t start = 0; // string ó������ �˻�
	while ((start = str.find(from, start)) != string::npos) // from�� ã�� �� ���� ������
	{
		// ���⼭ start�� from ���ڸ� �߰��� �ε��� ��ġ
		str.replace(start, from.length(), to);
		start += to.length(); // �ߺ��˻縦 ���ϰ� from.length() > to.length()�� ��츦 ���ؼ�
	}
	return str;
}

int main()
{
	// �ܾ� �ϳ��� �ٲٴ� ���
	string str1 = "blah#blah";
	replace(str1.begin(), str1.end(), 'a', '?'); // bl?h#bl?h
	cout << str1 << endl;

	// ���ڸ� �ٲٴ� ���
	string str2 = "Number Of Beans";
	string str3 = "ghghjghugtghty";
	string str4 = "ghghjghugtghty";
	std::cout << replaceAll(str2, std::string(" "), std::string("_")) << std::endl;
	std::cout << replaceAll(str3, std::string("gh"), std::string("X")) << std::endl;
	std::cout << replaceAll(str4, std::string("gh"), std::string("h")) << std::endl;
}