#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

deque<char> dq_front;
deque<char> dq_back;
string a, t;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> t;

	int s = 0, e = t.length() - 1;

	// �������簡 30�� * 30�� = 900��
	while (s <= e)
	{
		while (s <= e) // �տ������� �˿� ����
		{
			bool ok = false;
			dq_front.push_back(t[s++]);
			if (dq_front.size() >= a.length())
			{
				ok = true;
				for (int i = 0; i < a.length(); i++)
				{
					// a ���ڿ� ���ؼ� �˿��Ѵ�. �񱳴� �ִ� 25��
					if (a[i] != dq_front[dq_front.size() - a.length() + i])
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				for (int i = 0; i < a.length(); i++)
					dq_front.pop_back();
				break;
			}
		}

		while (s <= e)
		{
			bool ok = false;
			dq_back.push_front(t[e--]);
			if (dq_back.size() >= a.length())
			{
				ok = true;
				for (int i = 0; i < a.length(); i++)
				{
					if (a[i] != dq_back[i])
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				for (int i = 0; i < a.length(); i++)
					dq_back.pop_front();
				break;
			}
		}
	}

	// �� ���� ���� ��ĥ ������ ���ο� A��� ���ڿ��� ���� �� �����Ƿ� �� ���� �������ش�.
	string ret;
	for (int i = 0; i < dq_front.size(); i++)
		ret.push_back(dq_front[i]);
	for (int i = 0; i < dq_back.size(); i++)
		ret.push_back(dq_back[i]);

	// �ռ� �������簡 900���̹Ƿ� �߷����� ���´ٸ� �� ���̴� 3�� �Ʒ��� ���̴�.
	// ���� �� �ȿ� index �� ��� ã�Ƽ� �����ָ� ��
	while (ret.find(a) < 30000)
		ret.erase(ret.find(a), a.length());

	cout << ret << '\n';
	return 0;
}