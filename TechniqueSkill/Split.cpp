#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
	# C++���� string ���ڿ��� �޾ƿ� split �ϱ�

	1. istringstreama �� getline ���
	2. string�� find �� substr ���
*/

int main()
{
	/* �����ڰ� �ִ� ��� split���� �߶� vector�� �ֱ� */
	string str = "java c c++ python";
	istringstream ss(str);
	string stringBuffer;
	vector<string> v;

	// �����ڰ� ',' �̸� getline(ss, stringBuffer, ',') �� �ϸ� �ȴ�.
	while (getline(ss, stringBuffer, ' '))
	{
		v.push_back(stringBuffer);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	
	/* �ٸ� ���� */
	cout << endl;
	string as = "this,is,string";
	istringstream ss2(as);
	string stringBuffer2;
	while (getline(ss2, stringBuffer2, ','))
		cout << stringBuffer2 << ' ';
	cout << endl;

	/* string�� find �Լ��� substr Ȱ�� */
	cout << endl;
	as = "this,is,string";
	size_t previous = 0, current;
	current = as.find(',');
	// find �Լ��� �ش� ��ġ���� ���ڿ��� ã�� ���� ��� npos�� ��ȯ�Ѵ�.
	while (current != string::npos)
	{
		string substring = as.substr(previous, current - previous);
		cout << substring << ' ';
		previous = current + 1;
		// previous���� ,�� ������ ��ġ�� ã�´�.
		current = as.find(',', previous);
	}

	// ������ ���ڿ� ���
	cout << as.substr(previous, current - previous);

	return 0;
}