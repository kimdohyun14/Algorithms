#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	(cin >> n).get();
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum += s[i] - '0';
	}

	cout << sum << '\n';
	return 0;
}