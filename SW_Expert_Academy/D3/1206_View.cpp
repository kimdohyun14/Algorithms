#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int end = 0;
		int answer = 0;
		cin >> end;
		vector<int> v(end);

		//  ���� �������� ���� ����
		for (int i = 0; i < end; i++)
		{
			cin >> v[i];
		}

		vector<int> buildings(5);
		for (int start = 2; start < end - 2; start++)
		{
			// �ڽ��� ������ ��ġ(start)�� �������� ���� -1, -2 ������ +1, +2�� ���캻��.
			// �ڽ��� ������ 5�� �߿��� ���� ū �Ͱ� �� �������� ū ���� ã�´�.
			buildings[0] = v[start - 2];
			buildings[1] = v[start - 1];
			buildings[2] = v[start];
			buildings[3] = v[start + 1];
			buildings[4] = v[start + 2];

			sort(buildings.begin(), buildings.end());

			// ���� ū ������ ���̰� ���� �ڽ��� ������ �ƴ϶�� �н�
			if (v[start] != buildings[4])
				continue;
			else // ���信 �߰�
				answer += buildings[4] - buildings[3];
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}