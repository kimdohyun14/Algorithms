#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> mp;

    int index = 1;
    mp[words[0]]++;
    string prev = words[0];
    for (int i = 1; i < words.size(); i++, index++) {
        if (index == n) index = 0;
        // �̹� ������ ��ϵǾ� �ִ� ���
        if (mp[words[i]] > 0) {
            answer[0] = index + 1;
            answer[1] = (i / n) + 1;
            break;
        }

        // �����ձⰡ Ʋ�� ���
        if (prev.back() != words[i].front()) {
            answer[0] = index + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        else {
            prev = words[i];
            mp[words[i]]++;
        }
    }

    return answer;
}