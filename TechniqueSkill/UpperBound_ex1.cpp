#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 0,1,3,4,5 };

	int K = 2;
	int answer = 0;
	// ���� ��ġ���� K ���ϸ�ŭ ���̳��� ���� ������ ī��Ʈ �ϴ� ���
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		answer += ((upper_bound(iter, v.end(), *iter + K) - iter) - 1);
	}

	cout << answer << endl;
	return 0;
}