#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string str = "java c c++ python";
	istringstream ss(str);
	istringstream ss2(str);
	string stringBuffer;
	string str_copy;
	string str_copy2;
	vector<string> x;
	int ss_count = 0;
	//ss.str() ���ڿ��� ����
	cout << "ss.str()-> " << ss.str() << endl;
	//ss�� ũ��� ���ڿ��� ����
	cout << "ss.str().size() : " << ss.str().size() << endl;

	//�߸� ss�� �ٸ� ���ڿ��� copy
	cout << "copy-> ";
	while (ss >> str_copy) cout << str_copy << ",";
	cout << endl;

	cout << "vector-> \n";
	while (ss2 >> str_copy2) {
		x.push_back(str_copy2);
		ss_count++;
	}

	for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
	cout << "size : " << ss_count << endl;
	return 0;
}