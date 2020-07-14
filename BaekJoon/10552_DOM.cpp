// ��ó : https://withallmy.tistory.com/187
// �� Ǯ���� �ʾƼ� ������.
#include <iostream>

#define MAX_SIZE 100000 + 1
using namespace std;

int person[MAX_SIZE];
bool visited[MAX_SIZE];
int N, M, P, ans;

void dfs(int node)
{
	if (!visited[node])
	{
		visited[node] = true;
		if (person[node] != 0)
		{
			ans++; // ä���� �� �� ���������ϱ�
			dfs(person[node]);
		}
	}
	else
		ans = -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> P;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		// ���� � ����� �����ϴ� ä���� �ٲٹǷ�
		if (person[b] == 0)
			person[b] = a;
	}

	// ���� Ʋ�����ִ� ä�κ��� Ž������
	dfs(P);
	cout << ans << '\n';
	return 0;
}