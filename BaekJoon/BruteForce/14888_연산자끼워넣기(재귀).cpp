#include <iostream>
#include <vector>
using namespace std;

long long max_value = -1000000000;
long long min_value = 1000000000;

void solve(vector<int>& v, int index, long long sum, int plus, int minus, int mul, int div)
{
	// �Ұ����� ���
	if (plus < 0 || minus < 0 || mul < 0 || div < 0)
		return;

	// ������ ���
	if (v.size() == index)
	{
		if (max_value < sum) max_value = sum;
		if (min_value > sum) min_value = sum;
		return;
	}

	// ������ ���
	if (plus > 0)
	{
		solve(v, index + 1, sum + v[index], plus - 1, minus, mul, div);
	}

	if (minus > 0)
	{
		solve(v, index + 1, sum - v[index], plus, minus - 1, mul, div);
	}

	if (mul > 0)
	{
		solve(v, index + 1, sum * v[index], plus, minus, mul - 1, div);
	}

	if (div > 0)
	{
		solve(v, index + 1, sum / v[index], plus, minus, mul, div - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> op(4);
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	solve(v, 1, v[0], op[0], op[1], op[2], op[3]);
	cout << max_value << '\n' << min_value;
	return 0;
}