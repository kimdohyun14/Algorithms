#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// V ����, E ����
// �ð� ���⵵ O(VE)

vector<int> v[100];
int dist[100]; // dist[i] : ���� ��� ~ i��° �������� �ִ� �Ÿ�

void dfs(int node)
{
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		// ���� �湮���� �ʾҰų�, �̹� ���� ��κ��� �� ���� ��θ� ã�Ҵٸ�
		if (dist[next] == -1 || dist[next] > dist[node] + 1)
		{
			dist[next] = dist[node] + 1;
			dfs(next);
		}
	}
}

int main() // ���� ����ġ�� ����
{
	memset(dist, -1, sizeof(dist)); // �ʱ�ȭ
	dfs(1);
	return 0;
}