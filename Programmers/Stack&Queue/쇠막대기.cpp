#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int len = arrangement.size();
    stack<int> iron;
    
    char prev = arrangement[0]; // ó������ (
    char now;
    int ironCnt = 0;
    for(int i = 1; i < len; i++){
        if(prev == '('){
            if(arrangement[i] == '('){ // "((" �踷�������
                ironCnt++;
                iron.push(ironCnt);
            }else if(arrangement[i] == ')'){ // "()" ����������
                answer+=iron.size();
            }       
        }else{
            // ")(" �� ���� �ǹ̰� ����.
            if(arrangement[i] == ')'){ // "))" �踷��Ⱘ��
                ironCnt--;
                iron.pop();
                answer++;
            }
        }
        prev = arrangement[i]; //������ ���� ������ �� ���� �����̱� ������
    }
    
    return answer;
}
