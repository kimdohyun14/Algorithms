#include <string>
#include <vector>

using namespace std;

// ��ȭ��ȣ�� �� 4�ڸ��� ������ ������ ���ڸ� ���� * �� ó��
string solution(string phone_number) {
	int len = phone_number.length();
	for (int i = 0; i < len - 4; ++i)
		phone_number[i] = '*';

	return phone_number;
}