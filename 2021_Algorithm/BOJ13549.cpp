#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 100001;
const int INF = INT_MAX;

int n, k;
int dist[MAX];

// X -> 2X 0���̹Ƿ�, �ܼ��� �湮�ߴٴ� true/false�� �ƴϰ�,
// �� ���� �ð����� ������ ã���� �ǹǷ� �� ���� ��츦 ã�Ҵٸ� �װ��� �����̴�.

void input()
{
	cin >> n >> k;
	fill(dist, dist + MAX, INF);
}

void findBrother()
{
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k) return;

		// �� ���� ��θ� ã�Ҵٸ� �����ϱ�
		if (cur * 2 < MAX && dist[cur * 2] > dist[cur])
		{
			dist[cur * 2] = dist[cur];
			q.push(cur * 2);
		}

		if (cur + 1 < MAX && dist[cur + 1] > dist[cur])
		{
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}

		if (cur - 1 >= 0 && dist[cur - 1] > dist[cur])
		{
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
	}
}

void solve()
{
	input();
	findBrother();
	cout << dist[k] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}