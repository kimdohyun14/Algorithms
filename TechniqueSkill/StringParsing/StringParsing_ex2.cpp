#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string str = "java c c++ python";
	istringstream ss(str);
	string buffer;
	vector<string> v;
	//' '�� �����ڷ� split�ؼ� vector�� �ֱ�
	while (getline(ss, buffer, ' '))
	{
		v.push_back(buffer);
	}

	for (string s : v)
		cout << s << endl;

	return 0;
}