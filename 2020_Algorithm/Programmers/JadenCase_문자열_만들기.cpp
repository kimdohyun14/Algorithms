#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    vector<string> v;
    string temp;
    // �� ������ ' '�� �������� ������ ���ڿ��� ���Ϳ� ����
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        else {
            v.push_back(temp);
            temp.clear();
        }
    }
    v.push_back(temp);

    // ���ڿ��� ù ���ڸ� �빮�ڷ� ����, �� ���� ���ڴ� �ҹ��ڷ� ����
    for (int i = 0; i < v.size(); ++i) {
        string& str = v[i];
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        for (int j = 1; j < str.length(); ++j) {
            if (str[j] >= 'A' && str[j] <= 'Z')
                str[j] += 32;
        }
    }

    // ���͸� �ٽ� string ��ü�� �ű��.
    string answer = "";
    answer += v[0];
    for (int i = 1; i < v.size(); ++i) {
        answer += " ";
        answer += v[i];
    }

    return answer;
}