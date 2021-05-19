#include <string>
#include <vector>

using namespace std;

long long dp[81]; //dp[i] : Ÿ���� ������ i���� ��, �ѷ��� ����

long long solution(int N) {
    
    dp[1] = 4, dp[2] = 6;
    for(int i = 3; i <= 80; ++i){
        dp[i] = dp[i - 1]+dp[i - 2];
    }
    return dp[N];
}
