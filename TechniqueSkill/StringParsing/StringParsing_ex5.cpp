/*
	���ڿ��� ������ stringstream
	�־��� ���ڿ����� �ʿ��� �ڷ����� �´� ������ ���� �� ����

	����� '\n'�� �����ϰ� ���ڿ����� �´� �ڷ����� ������ ����.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	string str = "123 456 789";
	stringstream ss(str); // ���� stream ���� ���ڿ� str�� ����
	while (ss >> n) cout << n << endl;
	cout << endl;

	vector<int> time;
	string query = "2021:05:15 12:59:31";
	for (int i = 0; i < query.size(); i++)
	{
		if (query[i] == ':') query[i] = ' ';
	}

	stringstream ss2(query);
	//while (ss2 >> n) time.push_back(n);
	//for (auto p : time) cout << p << endl;
	//cout << endl;

	string str2;
	vector<string> time2;
	while (ss2 >> str2) time2.push_back(str2);
	for (auto p : time2) cout << p << endl;
	cout << endl;
	return 0;
}