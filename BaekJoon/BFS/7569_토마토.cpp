#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int a[101][101][101];         // �丶�� ����
bool visited[101][101][101];  // �湮 �迭
int r, c, h;                  // ��, ��, ����

typedef struct pos
{
	int z;
	int x;
	int y;
}Pos;

/* Ȯ���ϴ� �뵵 */
void show()
{
	cout << '\n';
	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < r; j++) 
		{
			for (int k = 0; k < c; k++)
				cout << a[i][j][k] << ' ';
			cout << '\n';
		}
	}
}


/* BFS Ž�� */
void bfs(queue<Pos> &q)
{
	while (!q.empty())
	{
		int z = q.front().z;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			// ��� üũ
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && nz >= 0 && nz < h)
			{
				// �湮���� �ʾ����鼭 ���ÿ� �� ������ ���� ���� �丶����
				if (visited[nz][nx][ny] == false && a[nz][nx][ny] == 0)
				{
					visited[nz][nx][ny] = true;
					a[nz][nx][ny] = a[z][x][y] + 1;
					q.push({ nz,nx,ny });
				}
			}
		}
	}
}

int check()
{
	/* �丶�䰡 �ƿ� ���� ���� ���� �ִٸ� */
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				if (a[i][j][k] == 0) return -1;

	/* �ƴ϶�� ������ �丶�䰡 ���� ������ ��¥ ��� */
	int day = 1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				if (day < a[i][j][k])
					day = a[i][j][k];
	
	if (day == 1) // �丶�䰡 ó������ ��� �;��ִٴ� ��
		return 0;
	else
		return day - 1;
}


int main()
{
	queue<Pos> q;

	/* �Է� */
	cin >> c >> r >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
			{
				cin >> a[i][j][k];
				if (a[i][j][k] == 1) 
				{
					visited[i][j][k] = true;
					q.push({ i,j,k }); // �丶���� ��ġ ����
				}
					
			}
	/* Ž�� */
	bfs(q);
	int ret = check();

	/* ��� */
	cout << ret;
	return 0;
}