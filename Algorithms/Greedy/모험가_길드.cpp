#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	int result = 0; // �� �׷��� ��
	int count = 0;  // ���� �׷쿡 ���Ե� ���谡�� ��

	for (int i = 0; i < n; i++) { // �������� ���� �ͺ��� �ϳ��� Ȯ���ϸ鼭
		count += 1; // ���� �׷쿡 �ش� ���谡�� ���Խ�Ű��
		if (count >= arr[i]) { // ���� �׷쿡 ���Ե� ���谡�� ���� ������ ������ �̻��̶��, �׷� �Ἲ
			result += 1; // �� �׷��� �� ����
			count = 0;   // ���� �׷쿡 ���Ե� ���谡�� �� �ʱ�ȭ
		}
	}

	cout << result << '\n';
	return 0;
}