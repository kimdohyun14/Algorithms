#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// ������ �� �ڸ��� ���ϱ� �˰���

int main()
{
	int num = 123456789;

	// �̷��� �ɰ��� ���
	printf("case 1 : ");
	while (num)
	{
		printf("%d ", num % 10);
		num /= 10;
	}
	printf("\n");
	// ��� 9 8 7 6 5 4 3 2 1


	// �迭�� �����Ѵ��� �̿��ϴ� ���
	num = 123456789;
	vector<int> v1;
	while (num)
	{
		v1.push_back(num % 10);
		num /= 10;
	}
	printf("case 2 : ");
	for (int i = 0; i < v1.size(); i++)
		printf("%d ", v1[i]);
	printf("\n");

	// �������� ����غ���. (algorithm ������Ͽ� �ִ�)
	printf("case 3 : ");
	reverse(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++)
		printf("%d ", v1[i]);
	printf("\n");

	// ������ �̿��ؼ� �������� ��� ����
	printf("case 4 : ");
	stack<int> s;
	for (int i = 0; i < v1.size(); i++)
		s.push(v1[i]); // o(1)
	while (!s.empty()) 
	{
		printf("%d ", s.top()); // o(1)
		s.pop(); // o(1)
	}
	return 0;
}