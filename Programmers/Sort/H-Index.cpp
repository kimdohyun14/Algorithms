#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    bool chk = false;
    sort(citations.begin(), citations.end(), greater<int>()); //��������
    
    //�� size �� ��, h�� �̻� �ο�� ���� h�� �̻��̰�,
    //������ ���鵵 h�� ���Ϸ� �ο��ٸ�, �װ��� H-index
    //H-index�� 0����� �����ϸ�, ��Ģ�� ������ ����.
    //H-index�� H-index �̻� �ο�� ���� h�� �̻��̿��� �ǰ�,
    //���ÿ� ������ ������ h�� ���Ϸ� �ο�Ǿ�� �Ѵ�.
    for(int h = 0; h < citations.size(); h++){
        if(h >= citations[h]){ 
            answer = h;
            chk = true;
            break;
        }
    }
    if(chk) return answer;
    else return citations.size(); //������ �������� ������, ��ǥ�� ���� ������ ���̴�.
}
