#include <stdio.h>

int main()
{
	// ������ ������ ����
	int a = 5;
	int *b = &a;
	printf("%d\n", a);
	printf("%d\n", *b);

	// �迭 �� ������ �ּ� �� ���
	int c[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", &c[i]);
	}

	// ���� ������ ����
	int d = 10;
	int *e = &d;
	int **f = &e;
	printf("%d\n", d);
	printf("%d\n", *e);
	printf("%d\n", **f);

	// �����Ϳ� �迭�� ����
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int *arrPtr = arr; // �迭�� �̸� ��ü�� �迭�� ���� �ּҰ��̴�.
	printf("%d\n", arr[2]);
	printf("%d\n", arrPtr[2]);
	return 0;
}