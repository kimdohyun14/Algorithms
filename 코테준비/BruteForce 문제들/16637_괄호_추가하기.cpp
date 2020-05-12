// https://yabmoons.tistory.com/200

// ��ȣ�� �߰����� �ʰ� ����ϴ� ���
// ��ȣ�� ����� ����� ������ �������.. ���߿� �ٽ� Ǯ���.
#include <iostream>
#include <string>
#include <algorithm>

#define MAX 20
using namespace std;

int N, op_num;
int ans = -2147483640;
int num[MAX], op[MAX];

int calculate(int n1, int n2, char c)
{
	if (c == '+') return n1 + n2;
	else if (c == '-') return n1 - n2;
	else if (c == '*') return n1 * n2;
}

// idx : ���� �ε���
// result : ��������� �����
void dfs(int idx, int result)
{
	if (idx >= op_num)
	{
		ans = max(ans, result);
		return;
	}

	// ���� �����ڸ� �������� ��ȣ�� �߰��ϴ� ���
	int cur_result = calculate(result, num[idx + 1], op[idx]);
	dfs(idx + 1, cur_result);

	// ���� �����ڿ� ��ȣ�� �߰����� �ʰ�, ���� �����ڷ� ��ȣ�� �߰��ϴ� ���
	if (idx + 1 < op_num)
	{
		// ���� �����ȣ�� ��������, �� ĭ �� �Ѿ �����ȣ�� �����Ѵٸ�,
		// �� ĭ �Ѿ �����ȣ���� ���� ��� �Ŀ�, �� ������� ������ ������� ���� �����ȣ�� ���� ��� ��.
		// ��� ȣ��.
		int after_result = calculate(num[idx + 1], num[idx + 2], op[idx + 1]);
		int cur_result = calculate(result, after_result, op[idx]);
		dfs(idx + 2, cur_result);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	int idx = 0;
	int idx2 = 0;

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (i % 2 == 0) num[idx++] = str[i] - '0';
		else op[idx2++] = str[i];
	}

	op_num = N / 2;

	if (N == 1)
	{
		cout << num[0];
		return 0;
	}
	else if (N == 3)
	{
		cout << calculate(num[0], num[1], op[0]);
		return 0;
	
	}

	dfs(0, num[0]);
	cout << ans;
	return 0;
}