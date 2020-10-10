#include <iostream>
#include <map>
using namespace std;

// map
// ��ųʸ� �ڷᱸ��
// ���� ���̰� ����, Ž�� ���� ������ O(logN)�� �����Ѵ�.

int main()
{
	// int�ڷ����� key�� int�ڷ����� �����ͷ� �����ϴ� ��ųʸ� �ڷᱸ�� ����
	map<int, int> m;
	// (4,5)���� ����
	m.insert(make_pair(4, 5));
	// �Ǵ�
	m[5] = 6;
	// key�� ������ ���Ҹ� pair<Ű �ڷ���, ������ �ڷ���> ���·� �����Ѵ�.
	printf("key : %d, value : %d\n", m.find(4)->first, m.find(4)->second);
	printf("key : %d, value : %d\n", m.find(5)->first, m.find(5)->second);
	// key�� ������ ������ ������ ����
	printf("count : %d\n", m.count(4));
	// ����� ������ ���� ������
	printf("size : %d\n", m.size());
	// �ش� �ּ��� ���� ����
	m.erase(++m.begin());

	// map�� ����Ǿ��ִ� ��� ���� ���
	map<int, int>::iterator iter;
	for(iter = m.begin(); iter != m.end(); iter++)
		printf("key : %d, value : %d\n", iter->first, iter->second);

	// ��� ���� ����
	m.clear();
	return 0;
}