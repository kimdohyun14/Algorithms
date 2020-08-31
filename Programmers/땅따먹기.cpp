#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// i�� j���� �ְ����� ���Ϸ���, �ٽø��� land[i][j]�� ����?
// ���� �࿡���� j���� ������ ������ ���� �տ��� �ִ븦 ���� �ȴ�.
// ���� j = 0 �̶��,
// land[i-1][j+1], land[i-1][j+2], land[i-1][j+3] �� �� max ���� land[i][j]�� �־��ش�.

int solution(vector<vector<int> > land)
{
    int value = 0;
    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < land[i].size(); ++j) {
            value = 0;
            for (int k = 0; k < land[i].size(); ++k) {
                if (k == j) continue;
                if (value < land[i - 1][k])
                    value = land[i - 1][k];
            }
            land[i][j] += value;
        }
    }

    int row = land.size() - 1;
    int answer = *max_element(land[row].begin(), land[row].end());
    return answer;
}