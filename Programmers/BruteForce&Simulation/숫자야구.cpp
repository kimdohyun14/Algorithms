#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int strike = 0;
    int ball = 0;
    bool success = true;
    
    //���� �� �ִ� ���ڸ� �� ������ ���غ���.
    for(int i = 123; i <= 987; i++){
        int a = i % 10;         //���� �ڸ� 
        int b = (i / 10) % 10;  //���� �ڸ�
        int c = i / 100;        //���� �ڸ�
        success = true;
        
        if( a == b || a == c || b == c) continue;
        if( a == 0 || b == 0 || c == 0) continue;
        
        for(int j = 0; j < baseball.size(); j++){
            int ta = baseball[j][0] % 10;
            int tb = (baseball[j][0] / 10) % 10;
            int tc = baseball[j][0] / 100;
            strike = 0, ball = 0;
            
            if( ta == tb || ta == tc || tb == tc) continue;
            if( ta == 0 || tb == 0 || tc == 0) continue;
            
            
            //��Ʈ����ũ ���� Ȯ���Ѵ�. (������ �켱����)
            if( a == ta ) strike++;
            if( b == tb ) strike++;
            if( c == tc ) strike++;
            if( strike != baseball[j][1]){
                success = false;
                break;
            }
            
            if( a == tb || a == tc) ball++;
            if( b == ta || b == tc) ball++;
            if( c == ta || c == tb) ball++;
            if( ball != baseball[j][2]){
                success = false;
                break;
            }
        }
        
        if(success) answer++;
        
    }
    
    return answer;
}
