// https://jaimemin.tistory.com/838

// �迭���� ���ڸ� �̾Ƴ��� �۾��� split�� �̼��ؼ� Ʋ�ȴ�..
// �߰������� �ð��ʰ� ���� ������ �迭�� ���� �������� ����⺸�ٴ�
// deque�� �̿��ؼ� �տ��� ����, �ڿ��� ������ �������ִ� ������ �ּ� �̿��ϸ� �ȴ�.

// �߰������� ����
// R
// 0
// []
// �Է����� ������
// ���� [] �̴�.
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); // �ӵ� ���
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		string command, number;
		cin >> command >> N >> number;

		deque<int> dq;
		string temp;
		// ���� split�ϱ�
		for (int i = 0; i < number.size(); i++)
		{
			char ch = number[i];
			if (ch == '[') continue;
			else if (ch >= '0' && ch <= '9') temp += ch;
			else if (ch == ',' || ch == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool isFront = true; // �տ��� �̰ڴ�.
		bool ok = true;      // error ����
		for (int i = 0; i < command.size(); i++)
		{
			char ch = command[i];
			if (ch == 'R')
			{
				isFront = !isFront;
			}
			
			else if(ch == 'D')
			{
				if (dq.empty())
				{
					ok = false;
					cout << "error" << '\n';
					break;
				}
				
				if (isFront)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (ok == false) continue;

		if (isFront)
		{
			cout << "[";
			while (!dq.empty())
			{
				cout << dq.front();
				dq.pop_front();
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
		else
		{
			cout << "[";
			while (!dq.empty())
			{
				cout << dq.back();
				dq.pop_back();
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}
	return 0;
}