#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int length = s.size();
	int word_count = 1; // �ܾ��� ����

	// �� ������ ������ ������ �� ���� �ܾ��� ������ ģ��.

	// ���ۺ��� �������� ���ٸ�
	if (s[0] == ' ') {
		word_count = 0;
	}
	else {
		word_count = 1;
	}
	for (int i = 0; i < length; i++) {
		// ������ �������� �� ���� �ܾ��̹Ƿ� �߰��Ѵ�.
		// ��, ���� �ε����� ������ �ε����� �ƴϸ�
		if (i != length -1 && s[i] == ' ') {
			word_count++;
		}
		else if (i == length - 1 && s[i] == ' ') {

		}
	}
	cout << word_count;
	return 0;
}