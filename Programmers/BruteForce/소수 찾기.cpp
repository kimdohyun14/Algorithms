#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

//�Ҽ����� �ƴ��� �Ǻ�
bool prime(int num){ 
    if(num == 0) return false;
    if(num == 2) return true;
    
    int cycle = (int)sqrt(num);
    for(int i=2; i<=cycle; i++){
        if(num % i == 0) return false;
    }
    return true;
}
//�ش� ���ڿ��� ������ �ִ� ���̷� ���� �� �ִ���
bool usePaper(vector<int> copy, string str){
    int size = str.size();
    for(int i=0; i<size; i++){
        char ch = str[i];
        if(copy[(int)(ch-'0')] >= 1){
            copy[(int)(ch-'0')]--; //���� ���
        }else
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int size = numbers.size();
    
    vector<int> check(10, 0); //������ �ִ� ���� �迭
    for(int i=0; i<size; i++){
        int temp = (numbers[i]-'0');
        check[temp]++; //���� ���Ƚ�� ����
    }
    vector<char> v; 
    for(int i=0; i<size; i++){
        v.push_back(numbers[i]);
    }
        
    sort(v.begin(), v.end(), greater<char>());
    string str;
    for(int i=0; i<size; i++)
        str+=v[i];
    int maxValue = stoi(str); //���� �� �ִ� ���� ū���� ����
    
    vector<int> copy; //�������� �׽�Ʈ ���̽��� �������ؼ�
    for(int i=2; i<=maxValue; i++){
        if(prime(i)){ //�Ҽ����� üũ
            str = to_string(i);
            copy = check; //���� ���� �ʱ�ȭ
            if(usePaper(copy, str)) //������ �ִ� ���̷� ���� �� �ִ���
                answer++;
        }
    }
    
    return answer;
}
