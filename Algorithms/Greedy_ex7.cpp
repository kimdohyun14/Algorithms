#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int cnt0, cnt1;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;

	if (s[0] == '0') cnt1++;
	else cnt0++;

	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] != s[i + 1]) // ������ ��
		{
			if (s[i + 1] == '1') cnt0++; // 1�̸� 0���� �ٲٰ�
			else cnt1++;                 // 0�̸� 1�� �ٲٰ�
		}
	}

	cout << min(cnt0, cnt1) << '\n';
	return 0;
}
