#include <iostream>
using namespace std;

int n;
int a[101];

bool isAscending()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

bool isDescending()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1]) return false;
	}
	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (isAscending()) cout << "��������";
	else if (isDescending()) cout << "��������";
	else cout << "����";
	return 0;
}