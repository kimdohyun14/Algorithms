#include <bits/stdc++.h>
using namespace std;

// �־��� ������ �״�� ������ �� �ִ��� �ľ�
// ����Լ��� �����ϰ� �ۼ��� �� �ִ��� �ľ�

// "�������� ��ȣ ���ڿ�"�� �ε��� ��ȯ
int BalancedIndex(string p) {
    int count = 0; // ���� ��ȣ�� ����
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count++;
        else count--;
        if (count == 0) return i;
    }
    return -1;
}

// "�ùٸ� ��ȣ ���ڿ�"���� �Ǵ�
bool CheckProper(string p) {
    int count = 0; // ���� ��ȣ�� ����
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count++;
        else {
            if (count == 0) return false; // ���� ���� �ʴ� ��쿡 false ��ȯ
            count--;
        }
    }
    return true; // ���� �´� ��쿡 true ��ȯ
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    int index = BalancedIndex(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    // "�ùٸ� ��ȣ ���ڿ�"�̸�, v�� ���� �Լ��� ������ ����� �ٿ� ��ȯ
    if (CheckProper(u)) {
        answer = u + solution(v);
    }
    // "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ��� ������ ����
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2); // ù ��°�� ������ ���ڸ� ����
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}