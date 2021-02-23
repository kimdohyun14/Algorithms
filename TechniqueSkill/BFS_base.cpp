#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[100];    // �湮 �迭
vector<int> v[100]; // ���� ����Ʈ

int main()
{
	queue<int> q;
	q.push(1); // ���� ��� ����
	check[1] = true;
	while (!q.empty()) // ť�� ������� �� -> �� �̻� �� ���� ���� �� ����
	{
		int node = q.front(); // ť�� �� �� ����
		q.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (check[next]) continue; // �̹� �湮�� ����� ��ŵ
			check[next] = true; // �湮 üũ
			q.push(next);
		}
	}

	return 0;
}