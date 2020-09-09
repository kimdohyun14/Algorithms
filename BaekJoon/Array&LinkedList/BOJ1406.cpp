#include <bits/stdc++.h>
using namespace std;

// �������� ���� �߰��� ������ ������ ����ϰ� �Ͼ�ٸ� list�� �������.
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	string init;
	cin >> init;

	list<char> lt;
	for (auto c : init)
		lt.push_back(c);
	auto cursor = lt.end();

	int n;
	cin >> n;
	string temp;
	getline(cin, temp); // �Է� ���ۿ� �����ִ� ���๮�� ����
	while (n--) {
		string op;
		getline(cin, op);
		if (op[0] == 'P') {
			lt.insert(cursor, op[2]); // cursor �տ� ����
		}
		else if (op[0] == 'L') {
			if (cursor != lt.begin())
				cursor--;
		}
		else if (op[0] == 'D') {
			if (cursor != lt.end())
				cursor++;
		}
		else {
			if (cursor != lt.begin()) {
				cursor--;
				cursor = lt.erase(cursor); // cursor�� ���� ���Ҹ� ����Ű�� ��
			}
		}
	}

	for (auto c : lt)
		cout << c;
	return 0;
}