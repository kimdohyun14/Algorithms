#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int x, y;
	char direction;
}Robot;

int A, B, N, M;                    // ����
int a[101][101];                   // ��
pair<int, bool> visited[101][101]; // (�κ� ��ȣ, �湮 ����)
vector<Robot> robots(101);         // �κ�����
bool ok = true;                    // �ùķ��̼� ����

void show(Robot& now)
{
	cout << "[" << now.x << "," << now.y << "]" << ' ' << now.direction << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> A >> B >> N >> M;
	//cout << A << " " << B << " " << N << " " << M << endl;

	// �ʱ�
	for (int i = 1; i <= N; i++)
	{
		cin >> robots[i].x >> robots[i].y >> robots[i].direction;
		visited[robots[i].x][robots[i].y].first = i;
		visited[robots[i].x][robots[i].y].second = true;
	}

	// ���
	for (int i = 0; i < M; i++)
	{
		int robot_num, loop;
		char command;
		cin >> robot_num >> command >> loop;

		Robot& now = robots[robot_num]; // ���� �κ�
		int nx, ny;                     // ����� ����Ǿ��� ���� ��ǥ

		// ��ɾ�� �� F, R, L
		if (command == 'F')
		{
			if (now.direction == 'N')
			{
				for (int j = 0; j < loop; j++)
				{
					nx = now.x; ny = now.y + 1;

					// �ٸ� �κ��� �ִ��� üũ
					if (visited[nx][ny].second == true)
					{
						cout << "Robot " << robot_num << " crashes into robot " << visited[nx][ny].first << endl;
						ok = false;
						break;
					}

					// ��� üũ
					if (nx >= 1 && ny >= 1 && nx <= A && ny <= B)
					{
						visited[now.x][now.y].second = false;
						visited[nx][ny].second = true;
						now.x = nx;
						now.y = ny;
					}
					else
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						ok = false;
						break;
					}
				}
			}
			else if (now.direction == 'E')
			{
				for (int j = 0; j < loop; j++)
				{
					nx = now.x + 1; ny = now.y;

					if (visited[nx][ny].second == true)
					{
						cout << "Robot " << robot_num << " crashes into robot " << visited[nx][ny].first << endl;
						ok = false;
						break;
					}

					if (nx >= 1 && ny >= 1 && nx <= A && ny <= B)
					{
						visited[now.x][now.y].second = false;
						visited[nx][ny].second = true;
						now.x = nx;
						now.y = ny;
					}
					else
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						ok = false;
						break;
					}
				}
			}
			else if (now.direction == 'W')
			{
				for (int j = 0; j < loop; j++)
				{
					nx = now.x - 1; ny = now.y;
					
					if (visited[nx][ny].second == true)
					{
						cout << "Robot " << robot_num << " crashes into robot " << visited[nx][ny].first << endl;
						ok = false;
						break;
					}

					if (nx >= 1 && ny >= 1 && nx <= A && ny <= B)
					{
						visited[now.x][now.y].second = false;
						visited[nx][ny].second = true;
						now.x = nx;
						now.y = ny;
					}
					else
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						ok = false;
						break;
					}
				}
			}
			else if (now.direction == 'S')
			{
				for (int j = 0; j < loop; j++)
				{
					nx = now.x; ny = now.y - 1;

					if (visited[nx][ny].second == true)
					{
						cout << "Robot " << robot_num << " crashes into robot " << visited[nx][ny].first << endl;
						ok = false;
						break;
					}

					if (nx >= 1 && ny >= 1 && nx <= A && ny <= B)
					{
						visited[now.x][now.y].second = false;
						visited[nx][ny].second = true;
						now.x = nx;
						now.y = ny;
					}
					else
					{
						cout << "Robot " << robot_num << " crashes into the wall" << endl;
						ok = false;
						break;
					}
				}
			}

			// �浹�߻�!
			if (ok == false) break;
		}
		else if (command == 'R')
		{
			for (int j = 0; j < loop; j++)
			{
				if (now.direction == 'N') now.direction = 'E';
				else if (now.direction == 'S') now.direction = 'W';
				else if (now.direction == 'W') now.direction = 'N';
				else if (now.direction == 'E') now.direction = 'S';
			}
		}
		else if (command == 'L')
		{
			for (int j = 0; j < loop; j++)
			{
				if (now.direction == 'N') now.direction = 'W';
				else if (now.direction == 'S') now.direction = 'E';
				else if (now.direction == 'W') now.direction = 'S';
				else if (now.direction == 'E') now.direction = 'N';
			}
		}
	}

	if (ok) cout << "OK" << endl;


	return 0;
}