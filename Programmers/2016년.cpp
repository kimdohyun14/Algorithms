#include <string>
#include <vector>

using namespace std;


// 1�� 7�� (��) 0
// 1�� 1�� (��) 1
// 1�� 2�� (��) 2  
// 1�� 3�� (��) 3
// 1�� 4�� (��) 4
// 1�� 5�� (ȭ) 5
// 1�� 6�� (��) 6

// 5�� 24��
// 1 ~ 4�� �� : 31 + 29 + 31 + 30 = 121
// �� �ϼ� : 121 + 24 = 145
// 145 % 7 = 5 => ȭ����
string solution(int a, int b) {
    // �����̸� 2���� 29�ϱ���
    int days[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string str[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

    int total_days = b;
    for (int i = 1; i < a; ++i)
        total_days += days[i];

    return str[total_days % 7];
}