#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//priority_queue
struct Student {
	int good, time, no; // ��õ��,�Խõ� �ð�,��ȣ
};

struct compare {
	bool operator()(Student a, Student b) {
		if (a.good == b.good) {
			return a.time > b.time; // ���� ������ ������ ����
		}
		return a.good > b.good;
	}
};

int n, m;
vector<int> v;
Student student[101];
priority_queue<Student, vector<Student>, compare> pq;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 1; i <= 100; i++) {
		student[i].good = 0;
		student[i].time = -1;
		student[i].no = i;
	}

	for (int t = 0; t < v.size(); t++) {
		int i = v[t];
		//ó�� ��õ�� ���� �л��̶��
		if (student[i].time == -1) {
			student[i].good = 1;
			student[i].time = t;
			student[i].no = i;

			if (pq.size() < n)
				pq.push(student[i]);
			else {
				Student cur = pq.top();
				pq.pop();
				student[cur.no].good = 0;
				student[cur.no].time = -1;
				pq.push(student[i]);
			}
		}
		else {
			// ������ �켱���� ť�� ���� �͵��� ������ ���� �ȵǱ� ������
			// �ٽ� ������ ���� ��Ų������ �ٽ� �־���� �Ѵ�.
			priority_queue<Student, vector<Student>, compare> temp;
			while (!pq.empty()) {
				Student cur = pq.top();
				pq.pop();

				if (cur.no == i) cur.good += 1;

				temp.push(cur);
			}
			pq = temp;
		}
	}

	vector<int> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top().no);
		pq.pop();
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}