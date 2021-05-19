#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // hash map ���
    unordered_map<string, int> hash;

    // �����ڵ��� �켱 ���� ��Ų��.
    for (string name : participant)
        ++hash[name];
    
    // ������ �������� ���� ��Ų��.
    for (string name : completion)
        --hash[name];

    // hash map�� ���鼭
    for (auto elem : hash)
    {
        // �����ڵ��� ���ָ� �ߴٸ� 0������, �׷����� �������� ���ߴٸ�?
        if (elem.second > 0)
        {
            answer = elem.first;
            break;
        }
    }

    return answer;
}