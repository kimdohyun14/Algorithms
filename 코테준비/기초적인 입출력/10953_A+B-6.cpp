#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int tc;
	// C��Ÿ���� scanf�Լ��� �Է� ���� ������ ���ؼ� ���ڿ� ��Ģ ���̿� �ִ� �������� �̾ƿ� �� �ִ�.
	scanf("%d", &tc);
	while (tc--)
	{
		int a, b;
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}