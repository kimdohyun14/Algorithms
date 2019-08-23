#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// �׷� �ܾ�� �� ���ڰ� �����ؼ� ��Ÿ���� ��츦 ���Ѵ�.
// ccazzzzbb�� c,a,z,b�� ��� �����ؼ� ��Ÿ���Ƿ� �׷� �ܾ��̴�.
// aabbbccb�� b�� �������� ��Ÿ���Ƿ� �׷� �ܾ �ƴϴ�.

// a ~ z���� �迭�� ���� �ϳ��� ���������� üũ, �ƴ϶�� false
// �ܾ �ϳ��� �˻��ϸ鼭 �����ߴµ� �� �����ϸ� �� �ܾ�� �׷� �ܾ �ƴϴ�.


int main() {
	int n;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
	
		bool alpha[26]; // ���ĺ� üũ �迭
		bool ok = true;
		bool continue_check = true;
		memset(alpha, false, sizeof(alpha));
		cin >> s;

		int length = s.length();
		// ù �ܾ�� Ȯ�����ְ�
		char first_char = s[0];
		alpha[s[0] - 'a'] = true;

		// ���� �ܾ���� ����.
		for (int j = 1; j < length; j++) {
			// ������ �ٸ� ���ĺ��� ������
			if (s[j - 1] != s[j]) {
				// ó�� ��ŷ�ϴ� ���ĺ����� Ȯ��
				if (!alpha[s[j] - 'a'])
					alpha[s[j] - 'a'] = true;
				else {
					ok = false;
					break;
				}
			}
		}

		if (ok)
			ans++;
	}

	cout << ans;
	return 0;
}