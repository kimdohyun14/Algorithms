#include <iostream>
#include <string>
using namespace std;

int arr[26];
string s;

int main()
{
	fill(arr, arr + 26, -1);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (arr[s[i] - 'a'] == -1)
			arr[s[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}