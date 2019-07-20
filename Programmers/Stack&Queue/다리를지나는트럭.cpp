#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> ready; //������� Ʈ��
    vector<pair<int, int>> onBridge; //�ٸ� ���� �ִ� Ʈ��
    int cntTrucks = 0; //������ Ʈ���� ��
    int sumTrucks = 0; //�ٸ� ���� Ʈ���� ������ ��
    int temp = 0;
    int size = truck_weights.size();
    
    for(int i = 0; i < size; i++)
        ready.push(make_pair(truck_weights[i], bridge_length)); //�ٸ� �ǳʱ� �� ����
    
    while(true){
        answer++; //1�� ����
        //cout<<answer<<"��"<<endl;
        if(cntTrucks == size) break; //�� �����ߴٸ�
        if(!ready.empty()){
            temp = ready.front().first;
            //cout<<"������ Ʈ���� ���� ����: "<< sumTrucks + temp <<endl;
            if(sumTrucks + temp <= weight){ //�ٸ��� ����� ��ƿ �� �ִ� ���Զ��
                sumTrucks+=temp;
                 //�ٸ����� �ø���. (����, �ð�)
                onBridge.push_back(make_pair(ready.front().first, ready.front().second));
                ready.pop();
             }
        }
        if(!onBridge.empty()){ //�ٸ� ���� Ʈ���� �ִٸ�?
            for(int i = 0; i < onBridge.size(); i++){
                onBridge[i].second--; //1�ʿ� 1ĭ�� ����
                if(onBridge[i].second == 0){
                    cntTrucks++; //���������ϱ� ������ Ʈ���� �� ����
                    sumTrucks-=onBridge[i].first;
                }
            }
        }
    }
    return answer;
}
