#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    for(int i = 0; i < len; i++) //������ �������� �ʴ� �ִ�Ⱓ
        answer.push_back(len-1-i);
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(prices[i] > prices[j]){//���� ��ġ�� ���ݺ��� �� �������� ���ݴ밡 �ִٸ�
                answer[i] = j - i; //�����Ѵ�.
                break;
            }
        }
    }
    return answer;
}
