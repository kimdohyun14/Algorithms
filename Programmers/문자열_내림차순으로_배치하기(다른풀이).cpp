#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string s) {
    // string������ �����ϴ�.
    // ������������ �Ϸ��� greater<>()�� �������.
    sort(s.begin(), s.end(), greater<char>());
    return s;
}