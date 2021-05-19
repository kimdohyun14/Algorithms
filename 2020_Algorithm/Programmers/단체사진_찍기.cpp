#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int GetIdx(char ch, const vector<char>& character, const vector<int>& order) {

    int fnd = 0;
    // ch�� ���� ĳ�������� ã��
    for (int i = 0; i < character.size(); ++i) {
        if (character[i] == ch) {
            fnd = i;
            break;
        }
    }

    int idx = 0;
    // ���� ������ �������� �� ĳ������ ��ġ ã��
    for (int i = 0; i < order.size(); ++i) {
        if (order[i] == fnd) {
            idx = i;
            break;
        }
    }

    return idx;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<int> order = { 0,1,2,3,4,5,6,7 };
    vector<char> character = { 'A','C','F','J','M','N','R','T' };

    do {
        bool ok = true;
        for (int i = 0; i < data.size(); ++i) {
            int fnd1 = GetIdx(data[i][0], character, order);
            int fnd2 = GetIdx(data[i][2], character, order);
            char op = data[i][3];
            int dist = data[i][4] - '0' + 1; // �����δ� RT �پ������� 0�� �ƴ϶� 1�̱� ���� (���̰���)

            if (op == '=') {
                if (abs(fnd1 - fnd2) != dist) {
                    ok = false;
                    break;
                }
            }

            else if (op == '>') {
                if (abs(fnd1 - fnd2) <= dist) {
                    ok = false;
                    break;
                }
            }

            else if (op == '<') {
                if (abs(fnd1 - fnd2) >= dist) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) answer++;

    } while (next_permutation(order.begin(), order.end()));

    return answer;
}