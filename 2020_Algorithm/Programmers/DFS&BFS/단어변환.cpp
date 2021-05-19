#include <string>
#include <vector>
#include <tuple>
#include <queue>
#define MAX_VALUE 987654321
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = MAX_VALUE;
    queue<tuple<vector<string>, string, int>> q;
    
    //ó������ words�� ���� �ܾ�, ���� Ƚ�� �ֱ�.
    q.push(make_tuple(words, begin, 0));
    
    while(!q.empty()){
        vector<string> v = get<0>(q.front());
        string str = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop();
        
        //words���� ������ �ܾ target�� ���ٸ� (��ǥ����)
        if(str.compare(target) == 0){
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < v.size(); i++){
            int diff = 0;
            
            //���� ĭ���� �̵��Ϸ��� ������ ���̰� 1�̿��� �Ѵ�.
            for(int j = 0; j < str.size(); j++){
                if(str[j] != v[i][j])
                    diff++;
            }
            
            //���̰� 1�̶��, begin�� �� ĭ �����ϰ� �ǰ�,
            //���� words���� ���ߴ� ���ڿ��� �����.
            if(diff == 1){
                vector<string> temp = v;
                vector<string>::iterator iter =  temp.begin() + i;
                temp.erase(iter);
                //������ words, begin, cnt�� ť�� �ٽ� �ִ´�.
                q.push(make_tuple(temp, v[i], cnt + 1));
            }
        }
    }
    //���� ������ �� �����ٸ�
    if( answer == MAX_VALUE) return 0;
    else return answer;
}
