#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 501;

/*
	# �÷��̵���� �˰���
	��� ��忡�� �ٸ� ��� �������� �ִ� ��θ� ���ϴ� �˰���
	���̳��� ���α׷��� ����̱⵵ ��.

	# �ð� ���⵵
	O(N^3)

	# �ٽ���
	k�� ���İ��� ����� �ϸ�, ��ȭ���� ������ ����.
	D[a][b] = min(D[a][b], D[a][k] + D[k][b])
*/

int n, m; // ����� ����, ������ ����
int graph[MAX][MAX];

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < MAX; i++) fill(graph[i], graph[i] + MAX, INF);

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				graph[i][j] = 0;
		}
	}

	// �� ������ ���� ������ �Է� �޾�, �� ������ �ʱ�ȭ
	for (int i = 0; i < m; i++)
	{
		// a���� b�� ���� ����� c��� �����ϸ�
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// ������ �� ���� ���, ���� ���
			if (graph[i][j] == INF) cout << "INF ";
			else cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}