#include <string>
#include <vector>
#define SIZE 20
using namespace std;

int len, ans;
bool visit[SIZE];
//v : �迭 ����
//sum : ���� �� ��
//cnt : ����� ������ ����
//target : ���߷��� �ϴ� ����
//idx : ���� ������ �ε���
void dfs(const vector<int> &v, int sum, int cnt, int target, int idx){
    if(cnt == len){
        if(sum == target)
            ans++;
    }else{
        //���� ���ϰų� Ȥ�� ���ų�
        //���ϱ� ����
        dfs(v, sum + v[idx], cnt + 1, target, idx + 1);
        //���� ����
        dfs(v, sum - v[idx], cnt + 1, target, idx + 1);
    }
}

int solution(vector<int> numbers, int target) {
    len = numbers.size();
    dfs(numbers, 0, 0, target, 0);
    return ans;
}
