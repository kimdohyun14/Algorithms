#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 2 - ABC
// 3 - DEF
// 4 - GHI
// 5 - JKL
// 6 - MNO
// 7 - PQRS
// 8 - TUV
// 9 - WXYZ

vector<pair<string, int>> v;


void Setting() {
	v.push_back(make_pair("ABC", 2));
	v.push_back(make_pair("DEF", 3));
	v.push_back(make_pair("GHI", 4));
	v.push_back(make_pair("JKL", 5));
	v.push_back(make_pair("MNO", 6));
	v.push_back(make_pair("PQRS",7));
	v.push_back(make_pair("TUV", 8));
	v.push_back(make_pair("WXYZ",9));
}

bool Matching(char ch, int index) {
	int length = 3; // ���� ���̰� 3������
	// ��ȭ��ȣ ��ư 7���� 9���� ���̰� 4�̴�.
	if (v[index].second == 7 || v[index].second == 9) {
		length = 4;
	}
	for (int i = 0; i < length; i++) {
		if (ch == v[index].first[i])
			return true;
	}
	return false;
}

int main() {
	Setting();
	string phone_number_string;
	
	cin >> phone_number_string;

	int phone_number_length = phone_number_string.length();
	int phone_book_length = v.size();
	int time_count = 0;

	for (int i = 0; i < phone_number_length; i++) { // ���� �ܾ �ϳ��� ����.
		for (int j = 0; j < phone_book_length; j++) { // ����ϰ� �ִ� ��ȭ��ȣ�ο���
			if (Matching(phone_number_string[i], j)) { // �ܾ�� ���� ���ϴ� �׸��̶� ������ �ð��� �����ش�.
				time_count += v[j].second;
				break;
			}
		}
	}

	time_count += phone_number_length;
	cout << time_count;

	return 0;
}