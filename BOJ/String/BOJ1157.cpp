#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string s;
	cin >> s;

	int alpha[26];
	memset(alpha, 0, sizeof(alpha));

	int length = s.size();
	for (int i = 0; i < length; i++) {
		// ���ڰ� �ҹ��ڶ��
		if (s[i] >= 'a' && s[i] <= 'z') {
			alpha[s[i] - 'a']++;
		} // ���ڰ� �빮�ڶ��
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			alpha[s[i] - 'A']++;
		}
	}

	int max_value = 0;
	char ans_alpha;
	// ����� ���ĺ��� ���� �߿��� �ִ��� ã�´�.
	for (int i = 0; i < 26; i++) {
		if (max_value < alpha[i]) {
			max_value = alpha[i];
			ans_alpha = (char)(i + 'A');
		}
			
	}

	// ���� ���� ���� ���ĺ��� ���ڿ� ������ �κ��� �ִ��� üũ
	int check = 0;
	for (int i = 0; i < 26; i++) {
		if (max_value == alpha[i])
			check++;
	}

	// ������ �κ��� �����Ƿ�
	if (check > 1) {
		cout << "?";
	}
	else {
		cout << ans_alpha;
	}
	
	return 0;
}