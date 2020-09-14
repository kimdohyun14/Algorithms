// https://bcp0109.tistory.com/32
// ���߿� �ٽ� Ǯ���.(�������� �����)
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool visited[100001];  // �湮���� üũ
bool finished[100001]; // �湮�� ��忡�� ����Ŭ�� �̹� �̾Ҵ���
int arr[100001];

void DFS(int now) {
	if (visited[now]) return;

	visited[now] = true;
	int next = arr[now];

	if (visited[next] != true) DFS(next);
	else {
		if (finished[next] != true) {
			// ��尡 �������� ����Ŭ�� ������ ���ľ��Ѵ�.
			// ���� ���� ��尡 �ƴ� ���� ��� �������� �ϸ� ����Ŭ�� ������ ����
			cnt++; // �ڱ� �ڽ�
			for (int i = next; i != now; i = arr[i])
				cnt++;
		}
	}

	// ��� �۾��� ������ ���̻� ��� x 
	finished[now] = true;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(visited, visited + 100001, false);
		fill(finished, finished + 100001, false);
		cnt = 0;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			DFS(i);
		}

		cout << n - cnt << '\n';
	}
	return 0;
}