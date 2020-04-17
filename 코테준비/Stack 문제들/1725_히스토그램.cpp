// https://jaimemin.tistory.com/827
// ������ ������� Ǫ�� ����
// �߿��� ���� �� ���캸�� ����, ������ �� �ִ� ���� �����ϸ鼭 Ǫ�� ��

// ���̸� ������������ �׵�, ���� stack.top�� ���� ���뺸�� ũ�ų� ���ٸ� ���簢���� ���̸� �����.
// �������κ��� ������ �������θ� ���� �� �ִٰ� �����ϸ鼭 ���� �ð��� �ʿ�.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;

	vector<int> v(N + 1, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	stack<int> st;

	int ans = 0;
	for (int i = 0; i < N + 1; i++)
	{
		while (!st.empty() && v[st.top()] >= v[i])
		{
			int height = v[st.top()];
			st.pop();

			int width;
			// ���ʿ� ������׷��� �������� �ʴٸ�
			if (st.empty()) width = i;
			else width = i - st.top() - 1;

			ans = max(ans, height * width);
		}
		st.push(i);
	}

	cout << ans;
	return 0;
}