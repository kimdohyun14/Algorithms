#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// ���� ���ڴ� �Ⱦ�(����)
vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}