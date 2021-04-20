#include <iostream>
#include <list>
#include <string>
using namespace std;

string s;
int M;

// ���� ������ ����ϰ� �Ͼ�鼭 ���̰� 10��.
// list�� Ư¡�� �� �˰� ������ ���� �ذ��� �� �ִ�.
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> M;

	list<char> lt;
	for (int i = 0; i < s.length(); i++) lt.push_back(s[i]);
	auto cursor = lt.end();
	while (M--)
	{
		char ch, x;
		cin >> ch;

		if (ch == 'L')
		{
			if (cursor != lt.begin())
				cursor--;
		}
		else if (ch == 'D')
		{
			if (cursor != lt.end())
				cursor++;
		}
		else if (ch == 'B')
		{
			if (cursor != lt.begin())
			{
				// ���� �Ŀ� ���� ���Ҹ� ����Ŵ.
				cursor = lt.erase(--cursor);
			}
		}
		else if (ch == 'P')
		{
			cin >> x;
			// ������ �ݺ��ڰ� ����Ű�� ������ ����.
			lt.insert(cursor, x);
		}
	}


	for (auto iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter;
	cout << '\n';
	return 0;
}