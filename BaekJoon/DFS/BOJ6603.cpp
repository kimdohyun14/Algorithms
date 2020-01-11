#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& ans, vector<int>& v, int i, int count) {
	// ��������
	// �ζ� ��ȣ 6���� �� �������
	if (count == 6) {
		for (int num : ans) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}
	// �Ұ����� ���
	// ������ ��� �ε����̸� (���������� �������� ó��������, i�� ���ϴ� ��찡 ������ ����̹Ƿ�
	// i�� ������ �ζ� ������ ����� �ʴ����� üũ���ָ� �ȴ�.
	if (v.size() == i) return;
	// ������ ���
	// ���� �ε����� �ζ� ��ȣ�� ����o
	ans.push_back(v[i]);
	solve(ans, v, i + 1, count + 1);
	// ���� �� �ζ� ��ȣ�� �������� ���� ������ �ζ� �迭�� ������ �ȵǱ� ������
	ans.pop_back(); 
	// ���� �ε����� �ζ� ��ȣ�� ����x
	solve(ans, v, i + 1, count);
}

int main() {
	int number_size = 0;

	while (true) {
		cin >> number_size;
		if (number_size == 0)
			break;

		vector<int> number(number_size); // �־����� �ζ� ��ȣ
		vector<int> ans;                 // �־����� �ζ� ��ȣ �� 6���� ���� ��ȣ��
		for (int i = 0; i < number_size; i++) {
			cin >> number[i];
		}
		solve(ans, number, 0, 0);
		cout << '\n';
	}
	return 0;
}