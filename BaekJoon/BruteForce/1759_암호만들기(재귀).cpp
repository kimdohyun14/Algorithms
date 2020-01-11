#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;

bool IsPossible(string s)
{
	int vowels = 0;     // ����
	int consonants = 0; // ����

	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			vowels++;
		else
			consonants++;
	}

	// �ּ� �� ���� ������ �ּ� �� ���� �������� ����
	if (vowels >= 1 && consonants >= 2)
		return true;
	else
		return false;
}

void makePassword(vector<char>& v, int index, string s, int goal)
{
	// ������ ���
	if (s.size() == goal)
	{
		if (IsPossible(s))
		{
			for (auto x : s)
			{
				cout << x;
			}
			cout << '\n';
			return;
		}
	}

	// �Ұ����� ���
	if (index >= v.size())
		return;

	// ���� ���
	makePassword(v, index + 1, s + v[index], goal); // index ���ĺ��� ����
	makePassword(v, index + 1, s, goal);            // index ���ĺ��� ������
}


int main()
{
	cin >> L >> C;
	vector<char> v(C);
	for (int i = 0; i < C; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	makePassword(v, 0, "", L);
	return 0;
}