#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ���� ���ٹ�
// �켱 ���� ������ ���� ��ȣó�� ��ŷ�Ѵ�
// ���� �ϳ� ��� �� �κп��� BFS�� ���� �ٸ� ���� ã�´�. 
// �� �� ����� �ּڰ����� �����Ѵ�.

const int MAX = 101;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int N, answer = 987654321;
int board[MAX][MAX];
bool visit[MAX][MAX];

void print();
void findLand(int x, int y, int mark);
int linkBridge(int mark);

struct Node
{
	int x, y, cnt;
};

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j]) 
				board[i][j] = -1;
		}
	}

	int color = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == -1 && !visit[i][j])
				findLand(i, j, color++);
		}
	}

	for (int i = 1; i < color; i++)
	{
		answer = min(answer, linkBridge(i));
	}

	cout << answer;
	return 0;
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void findLand(int x, int y, int mark) // ���� ã�� ��ŷ�Ѵ�
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	board[x][y] = mark;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny]) continue;
			if (board[nx][ny] == -1)
			{
				board[nx][ny] = mark;
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int linkBridge(int mark) // �ٸ��� ���´�
{
	fill(visit[0], visit[0] + MAX * MAX, false);
	
	queue<Node> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == mark)
				q.push({ i,j,0 });
		}
	}

	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny]) continue;
			if (board[nx][ny] && board[nx][ny] != mark) return node.cnt; // ���� ã�� ���
			visit[nx][ny] = true;
			q.push({ nx,ny,node.cnt + 1 });
		}
	}

	return 987654321;
}