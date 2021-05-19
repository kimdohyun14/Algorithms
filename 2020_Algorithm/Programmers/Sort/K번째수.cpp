#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        vector<int> info; // i, j, k ���� �迭
        vector<int> temp; // array�� i ~ j���̷� Ŀ���� �迭
        for(int j = 0; j < 3; j++)
            info.push_back(commands[i][j]);
        
        int s = info[0];
        int e = info[1];
        int k = info[2];
        for(int j = s - 1; j <= e - 1; j++)
            temp.push_back(array[j]);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    return answer;
}
