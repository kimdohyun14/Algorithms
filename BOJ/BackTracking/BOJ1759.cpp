#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> v;
vector<bool> visit(26);
vector<bool> init(26);
int L, C;

//�ش� ���ڿ��� ������ �ִ� ���ĺ����� ���� �� �ִ���
//�ּ� �Ѱ��� ������ �ּ� �� ���� �������� ���� 
bool check(){
	int vowal = 0; //������ ����
	int consonant = 0; //������ ����
	
	if(visit[0]) vowal++;
	if(visit[4]) vowal++;
	if(visit[8]) vowal++;
	if(visit[14]) vowal++;
	if(visit[20]) vowal++;
	
	for(int i=0; i<26; i++){
		if(i==0 || i==4 || i==8 || i==14 || i==20)
			continue;
		if(visit[i]){
			consonant++;
		}
	}
	
	if(vowal > 0 && consonant > 1){
		return true;
	}else{
		return false;
    }
}

//string : �����Ǵ� ���ڿ�
//cnt : ���� ����� ����������
//s : ���ĺ� ����
//��ȣ�� ���ĺ��� �����ϴ� ������ �迭�Ѵ�. 
void solve(string str, int cnt, int s){
	int idx = v[s] - 'a';
	visit[idx] = true;
	
	if(cnt == L){ //��������
		if(check()){
			cout<<str<<'\n';			
		}
	}else{
		for(int i=s+1; i<C; i++){
			//���� ���ĺ��� ������� �ʾҴٸ� 
			if(visit[v[i]-'a'] == false){
				solve(str+v[i], cnt+1, i);//���	
			}
		}
	}
	//backTracking
	visit[idx] = false;
}

int main(){
	cin>>L>>C;
	for(int i=0; i<C; i++){
		char ch;
		cin>>ch;
		v.push_back(ch);
	}
	sort(v.begin(), v.end());
	
	string str = "";
	for(int i=0; i<=C-L; i++){
		visit = init; //�湮 �ʱ�ȭ 
		solve(str + v[i], 1, i);
	}
	return 0;
}
