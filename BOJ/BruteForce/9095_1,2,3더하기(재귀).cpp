#include <iostream>
using namespace std;

int solution(int sum, int goal)
{
	// �Ұ����� ���
	if (sum > goal)
		return 0;
	// ������ ���
	if (sum == goal)
		return 1;
	// ���� ���
	int ans = 0;
	for (int i = 1; i <= 3; i++)
		ans += solution(sum + i, goal);

	return ans;
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int goal;
		cin >> goal;

		cout << solution(0, goal) << '\n';
	}

	return 0;
}