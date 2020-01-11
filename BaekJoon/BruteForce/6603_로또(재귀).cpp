#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;
void makeLotto(vector<int>& v, int index, int count, int goal)
{
	// ������ ���
	if (count == goal)
	{
		for (auto x : lotto)
		{
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}

	// �Ұ����� ���
	if (index >= v.size())
		return;

	// ���� ���
	lotto.push_back(v[index]); // �ζ� ��ȣ�� ����o
	makeLotto(v, index + 1, count + 1, goal);
	lotto.pop_back();          // �ζ� ��ȣ�� ����x
	makeLotto(v, index + 1, count, goal);
}

int main()
{
	int k, s;
	
	while (1)
	{
		cin >> k;

		if (k == 0)
			break;

		vector<int> num(k);
		for (int i = 0; i < k; i++)
			cin >> num[i];

		makeLotto(num, 0, 0, 6);
		cout << '\n';
		//lotto.clear();
	}

	return 0;
}