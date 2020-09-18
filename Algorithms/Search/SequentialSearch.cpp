#include <bits/stdc++.h>
using namespace std;

// ���� Ž�� �ҽ��ڵ� ����
int SequentialSearch(int n, string target, vector<string>& arr) {
	// �� ���Ҹ� �ϳ��� Ȯ���ϸ�
	for (int i = 0; i < n; i++) {
		// ������ ���Ұ� ã���� �ϴ� ���ҿ� ������ ���
		if (arr[i] == target) {
			return i + 1; // ������ ��ġ ��ȯ
		}
	}
	return -1; // ���Ҹ� ã�� ���� ��� -1 ��ȯ
}

int n;
string target;
vector<string> arr;

int main() {
	cout << "������ ���� ������ �Է��� ���� �� ĭ ��� ã�� ���ڿ��� �Է��ϼ���.\n";
	cin >> n >> target;

	cout << "�ռ� ���� ���� ������ŭ ���ڿ��� �Է��ϼ���. ������ ���� �� ĭ���� �մϴ�.\n";
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		arr.push_back(x);
	}

	// ���� Ž�� ���� ��� ���
	cout << SequentialSearch(n, target, arr) << '\n';
	return 0;
}