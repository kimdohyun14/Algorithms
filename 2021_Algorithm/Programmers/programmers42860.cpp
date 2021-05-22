#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int i = 0;
    string make(name.size(), 'A');
    while (1) {
        make[i] = name[i];
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        if (make == name) break;
        //�� ĭ�� �̵����� �� ���� ���ڿ� �ٸ��ٸ� �װ����� �̵��ϱ�
        for (int k = 1; k < name.size(); k++) {
            int right = (i + k) % name.size();
            int left = (i + name.size() - k) % name.size();
            if (make[right] != name[right]) {
                i = right;
                answer += k;
                break;
            }
            else if (make[left] != name[left]) {
                i = left;
                answer += k;
                break;
            }
        }
    }
    return answer;
}