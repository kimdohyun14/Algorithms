#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    // ������ ���� ����� �߿�
    // ���̴� �ּ� 3�� ����, ���Ʒ��� �����̰� ����� ������̱� ������
    // 3�� �ƴϸ� �̸� ������ �� �ִ� ����� ������ �ʱ� �����̴�.
    int height = 3, weight = 0;
    while (1) {
        if (sum % height == 0) {
            weight = sum / height;

            // (����-2)*(����-2) = ����� �κа� ��ġ�ϸ� �����̴�.
            if ((weight - 2) * (height - 2) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }

        ++height;
    }

    return answer;
}