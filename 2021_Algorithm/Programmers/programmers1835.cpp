#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool isValid(vector<string>& data, string line) {
    for (int i = 0; i < data.size(); i++) {
        int dist = data[i][4] - '0';
        dist++; // 0 ~ 6 �����̹Ƿ�
        int a = -1, b = -1;
        for (int j = 0; j < line.size(); j++) {
            if (data[i][0] == line[j]) a = j;
            if (data[i][2] == line[j]) b = j;
            if (a != -1 && b != -1) break;
        }
        if (data[i][3] == '=' && (abs(a - b) != dist)) return false;
        else if (data[i][3] == '<' && (abs(a - b) >= dist)) return false;
        else if (data[i][3] == '>' && (abs(a - b) <= dist)) return false;
    }
    return true;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    int answer = 0;
    string line = "ACFJMNRT";
    do {
        if (isValid(data, line)) answer++;
    } while (next_permutation(line.begin(), line.end()));

    return answer;
}