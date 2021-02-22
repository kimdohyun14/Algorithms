#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> v;

int countByRange(vector<int>& v, int leftValue, int rightValue)
{
	vector<int>::iterator rightIdx = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIdx = lower_bound(v.begin(), v.end(), leftValue);
	return rightIdx - leftIdx;
}

int main()
{
	// �������� ���� n, ã���� �ϴ� �� x
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	// ���� [x, x] ������ �ִ� �������� ���� ���
	int answer = countByRange(v, x, x);

	if (answer == 0) cout << -1;
	else cout << answer;
	return 0;
}