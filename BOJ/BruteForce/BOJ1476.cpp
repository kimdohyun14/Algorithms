#include <iostream>
using namespace std;

int main(){
	int e = 1, s = 1, m = 1; //����, �¾�, ��
	int endE, endS, endM;    //�����ؾ��ϴ� ��ǥġ
	cin>>endE>>endS>>endM; 
	int year = 1;
	
	if(endE == 1 && endS == 1 && endM == 1){
		cout<<1;
		return 0;
	}
	
	
	while(true){
		year++; //1�⾿ ������ ������ 
		e++, s++, m++; //�� �༺�� �ֱ⵵ �����Ѵ�. 
		if(e >= 16) e = 1; 
		if(s >= 29) s = 1;
		if(m >= 20) m = 1;
		if(endE == e && endS == s && endM == m) //��ǥġ�� ���ٸ� �� 
			break;	
	} 
	cout<<year;
	return 0;
}
