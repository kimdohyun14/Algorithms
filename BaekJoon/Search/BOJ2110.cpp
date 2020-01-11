#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, c, ans;
vector<int> home;

void binarySearch(long long left, long long right){
	if(left<=right){
		long long mid = (left + right) / 2;
		int cnt = 1, idx = 0;
		int cycle = home.size();
		for(int i=1; i<cycle; i++){
			if(home[idx] + mid <= home[i]){
				cnt++;
				idx = i;
			}
		}
	

		if(cnt < c){ //���ϴ� ������ ��ġ���� ���� ���� ��ġ�� �Ǿ��ٸ�, ������ �ٿ�����. 
			binarySearch(left, mid - 1);
		}else{ //���ϴ� ������ ��ġ���� ���� ���� ���� ���� ��ġ�� �Ǿ��ٸ�, ������ �� ��������. 
			ans = mid;
			binarySearch(mid + 1, right);
		}
	}	
}


int main(){
	cin>>n>>c;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		home.push_back(temp);
	}
	
	sort(home.begin(),home.end());
	binarySearch(0, INT_MAX);
	cout<<ans;
	return 0;
}
