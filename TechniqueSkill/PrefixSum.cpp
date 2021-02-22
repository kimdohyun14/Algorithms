#include <iostream>
#include <vector>
using namespace std;

/*
	���� �� �˰���
	O(N + M) ���⼭�� N�� ������ ����, M�� ������ �ǹ��Ѵ�.
*/

int n = 5;
vector<int> v = { 10,20,30,40,50 };
vector<pair<int, int>> query = { {1,3},{2,5},{3,4} };

int main()
{
	// 1. ������ Prefix Sum �迭�� ���Ѵ�.
	vector<int> prefixSum(n + 1, 0);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		prefixSum[i + 1] = v[i] + prefixSum[i];
	}

	// 2. ������ ���� �� ���
	for (int i = 0; i < query.size(); i++)
	{
		int left = query[i].first;
		int right = query[i].second;

		cout << prefixSum[right] - prefixSum[left - 1] << '\n';
	}

	return 0;
}