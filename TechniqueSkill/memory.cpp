/* Heap, stack, static ������ �޸� */

// �޸� ������ ũ�� ����(stack), ��(heap), ������(data)�������� ����������.

// ������ ����(���� �޸�)
// ���� ������ static ������ �Ҵ�Ǵ� ����
// ���α׷��� ���۰� ���ÿ� �Ҵ�ǰ� ���α׷��� ����Ǿ�� �޸𸮿��� �Ҹ��

// ���� ����
// ������ Ÿ�ӿ� ũ�� ����
// �Լ� ȣ�� �� �����Ǵ� ���� ������ �Ű� ������ ����Ǵ� ����
// �Լ� ȣ���� �Ϸ�Ǹ� �����

// �� ����
// ��Ÿ�ӿ� ũ�� ����
// �������� �Ҵ�� ����

#include <stdio.h>
#include <stdlib.h>

void foo(int a);

int val = 10;                  // 'val' in data area
char string[] = "Hello World"; // 'string' in data area

int main()
{
	int i = 100; // 'i' in stack area
	foo(i);
	return 0;
}

void foo(int a)
{
	int* ptr = (int*)malloc(sizeof(int) * a); // 'ptr' in heap area
}