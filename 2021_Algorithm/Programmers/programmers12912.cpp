#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int a, int b) {
    // ���콺 ���� n(x + y) / 2
    // n : x�� y ������ ����
    // x : ���� ��
    // y : ū ��
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}