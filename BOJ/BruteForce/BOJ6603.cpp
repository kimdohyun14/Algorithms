#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int k;
	//K���� ���� �߿��� 6���� �����ϴ� ����
	//������� 1, �� 6��
	//���� �ʾ����� 0, �� k - 6��
	while (true) {
		cin >> k;
		if (k == 0) break;
		vector<int> s(k);    //���� S
		vector<int> select;  //�����ҷ��� ����

		//���� S�� �Է¹޴´�.
		for (int i = 0; i < s.size(); ++i) {
			cin >> s[i];
		}

		//������� 1�� select�� �߰�
		for (int i = 0; i < 6; ++i) {
			select.push_back(1);
		}

		//���� �ʾҴٸ� 0�� select�� �߰�
		for (int i = 0; i < k - 6; ++i) {
			select.push_back(0);
		}

		//������ �� ���� ���������� �����ϰ� ����.
		sort(select.begin(), select.end());

		//������ ������ �ִ� 2���� �迭
		vector<vector<int>> ans;

		//������ ���鼭 ���� �� �ִ� ��� �ζ� ��ȣ�� �����Ѵ�.
		do {
			vector<int> temp;
			for (int i = 0; i < select.size(); ++i) {
				if (select[i] == 1) {
					temp.push_back(s[i]);
				}
			}
			ans.push_back(temp);
		} while (next_permutation(select.begin(), select.end()));

		//�������� ���������� ����϶�� �Ͽ����Ƿ�
		sort(ans.begin(), ans.end());

		//����� ��� �ζ� ��ȣ�� ����Ѵ�.
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}