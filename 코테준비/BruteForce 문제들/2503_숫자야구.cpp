// https://yabmoons.tistory.com/86

// ȥ�� Ǯ���� ������, ��� �ֺ��� �����ִ� ������ �� �ᱹ �����ϰ� ���.
// ������ ���� ��, ������ �ƴ� �͵��� ���ܽ�Ű�� �κ��� �������...
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef struct
{
	int number;
	int strike;
	int ball;
}Game;

int n;
bool check[1000];
vector<Game> question;

int main()
{
	//freopen("input.txt", "r", stdin);
	memset(check, true, sizeof(check));

	// ���� �� ���� ������ �̸� �����ش�.
	for (int i = 123; i <= 999; i++)
	{
		string str = to_string(i);
		if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]) check[i] = false;
		if (str[0] == '0' || str[1] == '0' || str[2] == '0') check[i] = false;
	}

	// �Է�
	cin >> n;
	while (n--)
	{
		int num, s, b;
		cin >> num >> s >> b;
		Game g;
		g.number = num;
		g.strike = s;
		g.ball = b;

		question.push_back(g);
	}

	// ������� ���ؼ� ���� �� ���� ������ �����ش�.
	for (int i = 0; i < question.size(); i++)
	{
		int num = question[i].number;
		int strike = question[i].strike;
		int ball = question[i].ball;
		string origin = to_string(num);

		for (int j = 123; j <= 999; j++)
		{
			int temp_strike = 0;
			int temp_ball = 0;
			
			if (check[j] == true)
			{
				string temp = to_string(j);
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						if (a == b && origin[a] == temp[b]) temp_strike++;
						if (a != b && origin[a] == temp[b]) temp_ball++;
					}
				}

				// �����̶�� ������ �ĺ��� �´��� üũ, �ƴ� �͵��� �����
				if (strike != temp_strike || ball != temp_ball) check[j] = false;
			}
		}
	}

	// ��� �������� ������ Ȯ���� �Ŀ��� ��Ƴ��� ���ڵ��� �����̴�.
	int ans = 0;
	for (int i = 123; i <= 999; i++)
	{
		if (check[i] == true) ans++;
	}
	cout << ans << '\n';
	return 0;
}