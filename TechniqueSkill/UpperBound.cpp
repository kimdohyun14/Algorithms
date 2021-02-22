#include <iostream>
#include <vector>
using namespace std;

int upperBound(const vector<int>& v, int left, int right, const int& val)
{
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		// ã�� ���Ұ� val���� �۰ų� ���� ��
		// ���� �� �߿��� �� �ڿ� �ִ� �ε����� �ִ��� Ȯ���غ���.
		if (v[mid] <= val)
		{
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}

	return ans + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v = { 1,1,2,2,3,3,4 };
	int idx = upperBound(v, 0, v.size() - 1, 2);
	cout << idx << endl;
	return 0;
}