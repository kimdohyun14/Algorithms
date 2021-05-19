#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
    int len = heights.size();
    vector<int> answer(len, 0);
    stack<pair<int, int>> topInfo; //(ž ����, ž ��ȣ)
    queue<pair<int, int>> ready;   // ž ���
    
    for(int i = 0; i < len; i++)
        topInfo.push(make_pair(heights[i], i));
    
    int nowHeight = topInfo.top().first; //���� ž�� ����
    int nowNum = topInfo.top().second;   //���� ž�� ��ȣ
    topInfo.pop();
    while(!topInfo.empty()){
        int lookHeight = topInfo.top().first; //�ٶ󺸴� ž�� ����
        int lookNum = topInfo.top().second;   //�ٶ󺸴� ž�� ��ȣ
        topInfo.pop();
        
        if(nowHeight < lookHeight){ //�۽��� �� �ִٸ�
            answer[nowNum] = lookNum + 1;
            nowHeight = lookHeight;
            nowNum = lookNum;
        }else{
            ready.push(make_pair(lookHeight, lookNum));
        }
    }
    while(!ready.empty()){ //���� �������� ���� �κ��� ž�� �˻�
        int lookHeight = ready.front().first;
        int lookNum = ready.front().second;
        ready.pop();
        for(int j = lookNum-1; j >= 0; j--){
            if(heights[j] > lookHeight){
                answer[lookNum] = j + 1;
                break;
            }
        }
    }
    return answer;
} 
