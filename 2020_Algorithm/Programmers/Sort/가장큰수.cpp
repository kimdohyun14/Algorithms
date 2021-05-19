#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    string str1 = a + b;
    string str2 = b + a; 
    return str1 > str2;
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> v;
    for(int i=0; i<size; i++){
        string str = to_string(numbers[i]);
        v.push_back(str);
    }
    
    sort(v.begin(),v.end(), compare);
    for(int i=0; i<size; i++){
        answer+=v[i];
    }
    if(v[0] == "0"){ //���࿡ ���ڿ��� ������ 0���� �����ϰ� �ȴٸ�
        answer = "0";//���� 0�� ���ڿ��̹Ƿ�
        return answer;
    }else{
        return answer;
    }
}
