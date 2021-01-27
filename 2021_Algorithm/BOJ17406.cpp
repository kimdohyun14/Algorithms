#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int board[101][101];
int copyBoard[101][101];

// ���� ���ٹ�
// �迭�� �ð� �������� ������. -> ����

// 12 13 14 15 16
// 22          26
// 32          36
// 42          46
// 52 53 54 55 56

// left : ���� �Ϸ��� �ǹ�
// bottom : �Ʒ��� �Ϸ��� �ǹ�
// right : ���� �Ϸ��� �ǹ�
// up : ���� �Ϸ��� �ǹ�

// �ð� �������� ������ ���� ���
// ���� ��ġ 12�� tmp�� �����ϰ�, left -> bottom -> right -> up ������ ���Ҹ� �̵���Ų��.
// �� ������ ���� tmp�� �ִ� �� col + 1 �Ͽ� �־��ش�.

struct Info
{
	int r, c, s;
};

void print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void rotateBoard(int r, int c, int s)
{
	int S1 = r - s;
	int E1 = c - s;
	int S2 = r + s;
	int E2 = c + s;

	while(S1 < S2)
	{
		int tmp = copyBoard[S1][E1];

		for (int i = S1 + 1; i <= S2; i++)  // left block move
			copyBoard[i - 1][E1] = copyBoard[i][E1];

		for (int i = E1 + 1; i <= E2; i++)  // bottom block move
			copyBoard[S2][i - 1] = copyBoard[S2][i];

		for (int i = S2 - 1; i >= S1; i--)  // right block move
			copyBoard[i + 1][E2] = copyBoard[i][E2];

		for (int i = E2 - 1; i >= E1; i--)  // up block move
			copyBoard[S1][i + 1] = copyBoard[S1][i];


		copyBoard[S1][E1 + 1] = tmp;

		S1++;
		E1++;
		S2--;
		E2--;
	}
}

int calculate()
{
	int ret = 987654321;
	for (int i = 1; i <= N; i++)
	{
		int total = 0;
		for (int j = 1; j <= M; j++)
			total += copyBoard[i][j];

		ret = min(ret, total);
	}

	return ret;
}


int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	vector<Info> v(K);
	for (int i = 0; i < K; i++)
		cin >> v[i].r >> v[i].c >> v[i].s;

	vector<int> order(K);
	for (int i = 0; i < K; i++) 
		order[i] = i;

	int answer = 5000;

	// ��� ȸ�� ����� �� �����ϴµ�, ���Ƿ� �����ϱ� ������
	// �پ��� ������� ȸ�� ��Ű�� �� ���� ���� ���Ͽ� �ּڰ��� ã�´�.
	do
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				copyBoard[i][j] = board[i][j];

		for (int i = 0; i < order.size(); i++)
		{
			int idx = order[i];
			rotateBoard(v[idx].r, v[idx].c, v[idx].s);
		}

		answer = min(answer, calculate());

	} while (next_permutation(order.begin(), order.end()));

	cout << answer;
	return 0;
}