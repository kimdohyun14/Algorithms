#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// string, parsing
int n;
bool chk[26]; //��ҹ��ڸ� ����x
vector<string> ans;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	(cin >> n).get();
	//�ɼǵ��� ������
	for (int tc = 0; tc < n; tc++) {
		string str;
		getline(cin, str);

		//�ɼ��� �ܾ��� �ɰ��� ���Ϳ� �־��ش�.
		istringstream ss(str);
		string buf;
		vector<string> v;
		while (getline(ss, buf, ' ')) {
			v.push_back(buf);
		}
		
		bool ok = false;

		//��Ģ1 ����
		//�ܾ��� ù ���ڰ� ����Ű�� �����Ǿ����� Ȯ��
		string newStr;
		int idx = -1;
		for (int i = 0; i < v.size(); i++) {
			string word = v[i];
			
			//�ܾ��� ù���ڰ� ����Ű�� �ƴ϶�� �����ϱ�
			if (isupper(word[0]) && chk[word[0] - 'A'] == false) {
				chk[word[0] - 'A'] = true;

				if (i == 0)
					newStr += "[";
				else //ù �ܾ �ƴ� �ι�° �ܾ���ʹ� �տ� ������ �ٿ�����.
					newStr += " [";

				newStr += word[0];
				newStr += "]";
				newStr += word.substr(1);
				ok = true;
				idx = i;
				break;
			}
			else if (islower(word[0]) && chk[word[0] - 'a'] == false) {
				chk[word[0] - 'a'] = true;

				if (i == 0)
					newStr += "[";
				else
					newStr += " [";

				newStr += word[0];
				newStr += "]";
				newStr += word.substr(1);
				ok = true;
				idx = i;
				break;
			}
			else {
				if (i == 0) 
					newStr = word;
				else 
					newStr += " " + word;
			}
		}

		if (ok) {
			//����Ű�� ������ �ڿ� �ܾ���� �̾ �ٿ��ش�.
			for (int i = idx + 1; i < v.size(); i++) {
				newStr += " ";
				newStr += v[i];
			}
			ans.push_back(newStr);
			continue;
		}

		//��Ģ2 ����
		//�տ������� ��� �ܾ� �ϳ��ϳ� ���캸�鼭 ����Ű�� �������� �ʾҴٸ� �������ֱ�.
		newStr = "";
		for (int i = 0; i < str.size(); i++) {
			if (isupper(str[i]) && chk[str[i] - 'A'] == false) {
				chk[str[i] - 'A'] = true;
				newStr += "[";
				newStr += str[i];
				newStr += "]";
				newStr += str.substr(i + 1);
				ok = true;
				break;
			}
			else if (islower(str[i]) && chk[str[i] - 'a'] == false) {
				chk[str[i] - 'a'] = true;
				newStr += "[";
				newStr += str[i];
				newStr += "]";
				newStr += str.substr(i + 1);
				ok = true;
				break;
			}
			else
				newStr += str[i];
		}

		if (ok)
			ans.push_back(newStr);
			
		else
			ans.push_back(str);
	}

	for (string s : ans) {
		cout << s << '\n';
	}
	return 0;
}