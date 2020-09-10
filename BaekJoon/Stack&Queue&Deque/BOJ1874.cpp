#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	stack<int> st;   // ���ڸ� ���� ����
	vector<char> op; // +,-�� ���� ����
	queue<int> q;    // �Է� ���� ���ڸ� ���� ����(���ÿ� ������ �ϴ� ��)

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	// �ʱ� �۾�
	int cur = 1;
	int size = q.front();
	for (int i = 0; i < size; i++) {
		st.push(cur++);
		op.push_back('+');
	}
	q.pop();
	st.pop();
	op.push_back('-');

	bool ok = true;
	while (!q.empty()) {
		int now = q.front();

		if (st.empty()) {
			st.push(cur++);
			op.push_back('+');
		}

		// �Ұ����� ���(�������� �ش� ���ڸ� ���� �� ���� ���)
		else if (st.top() > now) {
			ok = false;
			break;
		}

		else if (st.top() == now) {
			st.pop();
			q.pop();
			op.push_back('-');
		}
		
		else {
			st.push(cur++);
			op.push_back('+');
		}
	}

	if (ok) {
		for (auto c : op)
			cout << c << '\n';
	}
	else cout << "NO\n";
	return 0;
}