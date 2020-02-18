#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int check[26];
int n;
int ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		memset(check, 0, sizeof(check));
		bool ok = true;
		string str;
		cin >> str;

		// �ܾ� üũ
		for (int j = 0; j < str.length() - 1; j++)
		{
			if (str[j] != str[j + 1])
			{
				check[str[j] - 'a']++;
			}
		}
		// ������ �ܾ �ٽ� üũ
		check[str.back() - 'a']++;

		// ��ø�� �ִ��� üũ
		for (int k = 0; k < 26; k++)
		{
			if (check[k] >= 2)
			{
				ok = false;
				break;
			}
		}

		if (ok)
			ans++;
	}
	cout << ans;
	return 0;
}