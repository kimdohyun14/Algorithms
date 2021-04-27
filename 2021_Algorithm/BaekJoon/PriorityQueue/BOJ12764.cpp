#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int n;
pii input[100000 + 1];
set<int> computer;
int ret[100000 + 1];

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> input[i].first >> input[i].second;

	sort(input, input + n);

	// �ð� ���⵵
	// 10�� x log(10��) <= 1�� ���� ���
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		// ���ο� ����� �������� �� ��
		// ���� ����� ������� ��� �� �������� ���ش�.
		// �̶� �츮�� ���� �ڸ��� �� ���� �� �ִ� ��ȸ�� �ֿ�����.
		while (!pq.empty())
		{
			if (pq.top().first <= input[i].first)
			{
				computer.insert(pq.top().second);
				pq.pop();
			}
			else
				break;
		}

		// ���� �ڸ��� �����Ƿ� ���� ��ȣ�� ��ǻ�͸� �ο��Ѵ�.
		if (computer.empty())
		{
			pq.push({ input[i].second, cnt });
			ret[cnt]++;
			cnt++;
		}

		// ���� �ڸ��� �ִ�!
		// �� �ڸ��� ������ ���ְ� �����Ѵ�.
		else
		{
			auto iter = computer.begin();
			pq.push({ input[i].second, *iter });
			ret[*iter]++;
			computer.erase(iter);
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << ret[i] << ' ';
	cout << '\n';
	return 0;
}