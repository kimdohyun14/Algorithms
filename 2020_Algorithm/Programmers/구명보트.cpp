#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    // ���� Ž����� ������ �� ���¿��� ������ �ذ�����.
    sort(people.begin(), people.end());
    int l = 0, r = people.size() - 1;
    int answer = 0;
    while (l <= r) {
        // ���� ���ſ� ����� ���� �¿��.
        int total = limit - people[r--];

        // ���� ���� - �¿� ��� = ���� ����
        // ���� ���Կ��� ������ ����� �¿� �� �ִ��� Ȯ��
        if (total >= people[l]) {
            ++l;
        }

        ++answer;
    }

    return answer;
}