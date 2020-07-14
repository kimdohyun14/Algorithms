// ��ó : https://blog.naver.com/kks227/220613889973
// �� �ڵ尡 �ξ� �������� ���� �� ����.
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	string N, result = "0";
	int K;
	cin >> N >> K;
	queue<string> q;
	q.push(N);

	// K�� �����ϱ�
	for (int i = 0; i < K; i++)
	{
		int qSize = q.size();
		set<string> visited;
		// string�̱� ������ �迭 ��ſ� set�� ���
		for (int j = 0; j < qSize; j++)
		{
			string cur = q.front();
			q.pop();

			if (visited.count(cur)) continue;
			visited.insert(cur); // �湮üũ
			// ��� ������ �� �õ�
			for (int k = 0; k < cur.size() - 1; k++)
			{
				for (int l = k + 1; l < cur.size(); l++)
				{
					if (k > 0 || cur[l] != '0')
					{
						swap(cur[k], cur[l]);
						q.push(cur);
						swap(cur[k], cur[l]);
					}
				}
			}
		}
	}

	// ���� ū �� ����
	while (!q.empty())
	{
		result = max(result, q.front());
		q.pop();
	}

	if (result[0] == '0') cout << -1 << '\n';
	else cout << result << '\n';
	return 0;
}