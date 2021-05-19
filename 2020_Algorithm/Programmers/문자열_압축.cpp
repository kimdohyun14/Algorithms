#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ��ó: https://velog.io/@pa324/���α׷��ӽ�-Level-1-���ڿ�-����īī��-2020��ä-����
// ���ڿ��� ���̰� 1000�̹Ƿ�,
// ����� ����Ž������ Ǯ �� �־�����,
// ������ �κп��� �������..

int solution(string s) {
	int len = s.size();
	int answer = len;

	for (int i = 1; i <= (len / 2); ++i) {
		string result = "";
		string word = s.substr(0, i);
		int count = 1;

		for (int j = i; j <= len; j += i) {
			if (word == s.substr(j, i)) {
				++count;
			}
			else { // ���ڿ��� �ٸ���
				if (count == 1) {
					result += word;
				}
				else {
					result += (to_string(count) + word);
				}

				word = s.substr(j, i);
				count = 1;
			}
		}
		// �� ���ڿ��� �߰��� �Ǿ����� Ȯ��
		if (len / i != 0) {
			result += s.substr((len / i) * i);
		}
		if (answer > result.size())
			answer = result.size();
	}

	return answer;
}