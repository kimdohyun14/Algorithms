#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int a;
	char c;
	printf("�ϳ��� ���� �Է� : ");
	scanf("%d", &a);
	printf("%d\n", a);
	int temp;
	// �� �ھ� �޾Ƽ� ������ ���̰ų� ���� ���ڸ� ������ �Է��� ���߹Ƿ� �׻� �Է� ���۸� ����.
	while((temp = getchar()) != EOF && temp != '\n') { }
	printf("�ϳ��� ���� �Է� : ");
	scanf("%c", &c);
	printf("%c\n", c);
	while ((temp = getchar()) != EOF && temp != '\n') {}
	char *d = "Hello World";
	printf("%c\n", d[1]);
	printf("%c\n", d[4]);
	printf("%c\n", d[8]);

	printf("���ڿ� �Է� : ");
	char f[100];
	gets(f);
	printf("%s\n", f);


	// ���ڿ� ó���� ���� �پ��� �Լ���
	char k1[] = "dohyun";
	char k2[] = "dohyun";
	char k3[] = "dohyuf";
	printf("���ڿ��� ���� : %d\n", strlen(k1)); // 6
	printf("�� �迭�� ���� �� �� : %d\n", strcmp(k1, k2)); // 0
	printf("�� �迭�� ���� �� �� : %d\n", strcmp(k1, k3)); // 1
	strcpy(k3, k1);
	printf("����� ���ڿ� : %s\n", k3);
	printf("�� �迭�� ���� �� �� : %d\n", strcmp(k1, k3)); // 0

	char r1[20] = "My name is ";
	char r2[20] = "dohyun";
	printf("���ڿ��� ���� : %d\n", strlen(r1)); // 11
	printf("���ڿ��� ���� : %d\n", strlen(r2)); // 6
	strcat(r1, r2);
	printf("���ڿ��� ���� : %d\n", strlen(r1)); // 17

	char r3[20] = "i like that";
	char r4[20] = "that";
	printf("ã�� ���ڿ�: %s\n", strstr(r3, r4));
	return 0;
}