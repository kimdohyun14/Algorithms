#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	// scanf�Լ��� EOF�� ������ �Ǹ�, -1�� �����ϰ� �ȴ�.
	// �����̶��, ������ ���ڵ��� ���� �����Ѵ�.
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}
	return 0;
}