#include <iostream>
using namespace std;

int cnt;

// sum : ���� ���� ���� ����, goal : ������� �ϴ� ����
void Recursive(int sum, int goal)
{
	if (sum > goal) return;
	if (sum == goal)        
	{
		cnt++;
		return;
	}

	// ���� ���
	for (int i = 1; i <= 3; i++)
	{
		Recursive(sum + i, goal);
	}
}

int main()
{
	int caseCnt = 0, sum = 0;
	cin >> caseCnt;
	int N[10] = { 0, };
	for (int i = 0; i < caseCnt; i++)
	{
		cin >> N[i];
	}
	for (int i = 0; i < caseCnt; i++)
	{
		sum = 0, cnt = 0;

		Recursive(sum, N[i]);
		cout << cnt << '\n';
	}

	return 0;
}