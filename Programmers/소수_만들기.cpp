#include <vector>
#include <iostream>
using namespace std;

// �Ҽ� ���� �ƴ��� �Ǻ�
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

const int MAX = 1001;
int answer;
bool check[MAX];
// �迭�� �� �߿��� 3���� �̾� �Ҽ����� �ƴ��� �Ǻ�
void DFS(vector<int>& nums, int idx, int cnt) {
    if (cnt == 3) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (check[i] == true)
                sum += nums[i];
        }
        if (isPrime(sum)) ++answer;
        return;
    }

    for (int i = idx; i < nums.size(); ++i) {
        if (check[i] == true) continue;
        check[i] = true;
        DFS(nums, i, cnt + 1);
        check[i] = false;
    }
}

int solution(vector<int> nums) {
    DFS(nums, 0, 0);
    return answer;
}