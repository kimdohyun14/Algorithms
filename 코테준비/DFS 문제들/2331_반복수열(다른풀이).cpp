// https://jaimemin.tistory.com/946
// DFS �ε� Ǯ���� ���� �˾Ҵ�.
// visited[num]�� �� 3���� ������ �ϼ�����?

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 300000 + 1;

int A, P;
int visited[MAX];

void DFS(int num)
{
	visited[num]++;
	// �ݺ������� �� �� �ݺ��Ǿ��ٴ� ���� �ǹ�
	if (visited[num] == 3) return;

	int sum = 0;
	while (num)
	{
		sum += (int)pow((num % 10), P);
		num /= 10;
	}

	DFS(sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> P;

	DFS(A);
	int result = 0;
	//�� ���� ������ ���ڵ��� �ݺ������� ������ ���� ���ڵ�
	for (int i = 0; i < MAX; i++)
	{
		if (visited[i] == 1) result++;
	}

	cout << result;
	return 0;
}