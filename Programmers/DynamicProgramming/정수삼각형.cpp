#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[500][500]; // dp[i][j] : i��° ���̿� j��° �ε����� �� �� �ִ� �ִ밪�� ����

int solution(vector<vector<int>> triangle) {
    
    //���۾�
    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];
    
    int triangle_height = triangle.size();
    
    for(int i = 2; i < triangle_height; ++i){          //���� Ʈ���� ����
        for(int j = 0; j < triangle[i].size(); ++j){   //�ش� ������ �� ��° ĭ����
            if(j == 0 || j == triangle[i].size() - 1){
                //ù��°�� �� ���̸� ���� �Ʒ� �����ָ� �ȴ�.
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }else{
                //�װ� �ƴ϶�� 2���� �� max�� �����ؼ� �����Ѵ�.
                int temp = 0;
                for(int k = j - 1; k <= j; ++k){
                    temp = temp > dp[i - 1][k] ? temp : dp[i - 1][k];
                }
                dp[i][j] = temp + triangle[i][j];
            }
        }
    }
    
    int ans = 0;
    //���� ������ Ʈ�����̿��� ���� �ִ밪�� �����̹Ƿ�
    for(int i = 0; i < triangle_height; ++i){
        ans = ans > dp[triangle_height - 1][i] ? ans : dp[triangle_height - 1][i]; 
    }
    
    return ans;
}
