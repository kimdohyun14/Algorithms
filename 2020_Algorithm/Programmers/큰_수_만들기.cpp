#include <string>
#include <vector>
using namespace std;

// �׳� ������ ���� �ð��ʰ� �߻�, ���ڿ��� ���̰� �ִ� 100���̹Ƿ�
// �׷��� ������ ������ �н����ִ� Ž������� Ǯ��� �Ѵ�.
// 4177252841 k = 4�̸�,
// 41772 -> 7, idx = 2
// 725 -> 7, idx = 3
// 252 -> 5, idx = 5
// ... �ݺ�
string solution(string number, int k) {
    string answer = "";

    int choice = number.length() - k;
    int start = 0;
    for (int i = 0; i < choice; ++i) {
        char max_number = number[start];
        int max_idx = start;
        for (int j = start; j <= i + k; ++j) {
            if (max_number < number[j]) {
                max_idx = j;
                max_number = number[j];
            }
        }
        start = max_idx + 1;
        answer += max_number;
    }

    return answer;
}