#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int loop;
		cin >> loop;

		// C��Ÿ���� char str[] ���·� �Է¹޴´�.
		string str;
		cin >> str;

		// str.size()�� O(1)
		// C��Ÿ���� strlen()�� O(N)
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = 0; j < loop; j++)
				cout << str[i];
		}
		cout << '\n';
	}
	return 0;
}