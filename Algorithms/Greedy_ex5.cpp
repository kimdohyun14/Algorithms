#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ���谡 ���
int n;
vector<int> v;

int main()
{
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int result = 0; // �׷��� ��
	int cnt = 0;    // ���� �׷쿡 ���Ե� ���谡�� ��

	for (int i = 0; i < n; i++) // �������� ���� �ͺ��� �ϳ��� Ȯ���ϸ�
	{
		cnt++; // ���� �׷쿡 �ش� ���谡�� ����
		if (cnt >= v[i]) // ���� �׷쿡 ���Ե� ���谡�� ���� ���� ������ �̻��̶��, �׷� �Ἲ
		{
			result++;
			cnt = 0; // ���� �׷쿡 ���Ե� ���谡�� �� �ʱ�ȭ
		}
	}

	cout << result << '\n';
	return 0;
}
