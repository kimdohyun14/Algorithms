#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// �̹� ������ ���� �̻��ϴ�.
// ���� ��ġ���� ���������� �̵��� �Ͱ� �������� �̵��� ���� ���ٸ�,
// ���������� �̵��ϴ� ���� �����̰�, �������� �̵��ϰ� �Ǹ� ������ �ƴϰ� �ȴ�.
// ���̽�) BBBAAAB ���������� �̵��� �� 9 / �������� �̵��� �� 8

int ChangeAlphabet(int i, string str) {
    int up = str[i] - 'A';
    int down = 'Z' - str[i] + 1;

    return min(up, down);
}

int solution(string name) {
    int answer = 0;
    int cnt = 0;
    int len = name.length();
    vector<int> check(len, 0);
    for (int i = 0; i < len; ++i) {
        if (name[i] != 'A')
            cnt++;
        else
            check[i] = 1;
    }

    int idx = 0;
    for (int i = 0; i < cnt; ++i) {
        if (check[idx]) {
            int l_idx = idx;
            int r_idx = idx;
            int left = 0;
            int right = 0;

            // <-
            while (check[l_idx]) {
                if (l_idx == 0) l_idx = len - 1;
                else l_idx--;
                left++;
            }

            // ->
            while (check[r_idx]) {
                r_idx = (r_idx + 1) % len;
                right++;
            }

            if (left < right) {
                idx = l_idx;
                answer += left;
            }
            else {
                idx = r_idx;
                answer += right;
            }
        }
        check[idx] = 1;
        answer += ChangeAlphabet(idx, name);
    }
    return answer;
}