#include <iostream>
#include <string>
using namespace std;

// c�� ��� �ڿ� =, -
// d�� ��� �ڿ� -, ���࿡ z�̸� �ڿ� = Ȯ��
// l�� ��� �ڿ� j,
// n�� ��� �ڿ� j,
// s�� ��� �ڿ� =,
// z�� ��� �ڿ� =,

int main() {
	string s;
	cin >> s;
	int length = s.length();
	int alpha_count = 0;

	for (int i = 0; i < length; i++) {
		if (i + 1 < length && s[i] == 'c' && s[i + 1] == '=') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 'c' && s[i + 1] == '-') {
			alpha_count++;
			i++;
			continue;
		}
		else if (s[i] == 'd') {
			if (i + 1 < length && s[i + 1] == '-') {
				alpha_count++;
				i++;
				continue;
			}
			else if (i + 2 < length && s[i + 1] == 'z' && s[i + 2] == '=') {
				alpha_count++;
				i += 2;
				continue;
			}
			else {
				alpha_count++;
				continue;
			}
		}
		else if (i + 1 < length && s[i] == 'l' && s[i + 1] == 'j') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 'n' && s[i + 1] == 'j') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 's' && s[i + 1] == '=') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 'z' && s[i + 1] == '=') {
			alpha_count++;
			i++;
			continue;
		}
		else
			alpha_count++;
	}
	
	cout << alpha_count;
	return 0;
}