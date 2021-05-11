#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[100001]; // ù��° ��ƼĿ�� ���� ���
int dp2[100001]; // ù��° ��ƼĿ�� ���� �ʴ� ���
int solution(vector<int> sticker)
{
    int n = sticker.size();
    if (n == 1) return sticker[0];

    //ù ��° ��ƼĿ�� ���� ���
    dp1[0] = sticker[0];
    dp1[1] = sticker[0];
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }

    //ù ��° ��ƼĿ�� ���� �ʴ� ���
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
}