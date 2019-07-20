#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; //�� ��°�� ����ߴ���
    queue<pair<int,int>> q;
    for(int i = 0; i < priorities.size(); i++)
        q.push(make_pair(i, priorities[i])); //(���� ����, �߿䵵)�� ť�� ����
    while(!q.empty()){
        int order = q.front().first; //���� ����
        int value = q.front().second;//�߿䵵
        q.pop(); //���ť���� ����
        //������ �غ�ť���� ���� ���� �߿䵵�� �ִ´�.
        int listMaxValue = 0;
        for(int i = 0; i < priorities.size(); i++){
            if(listMaxValue < priorities[i])
                listMaxValue = priorities[i];
        }
        //cout<<value<<' '<<listMaxValue<<endl;
        if(value >= listMaxValue){
            answer++;
            priorities[order] = -1; //�ش� ������ �߿䵵�� ��������.
            if(location == order) break;
        }else
            q.push(make_pair(order,value)); //������� ���� �������� �ִ´�.
    }
    return answer;
}
