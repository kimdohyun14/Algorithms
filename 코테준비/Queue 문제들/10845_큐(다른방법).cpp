#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

void push(int x);   //push x : ���� x�� ť�� �ִ� �����̴�.
int pop(void);      //pop: ť�� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ���
int get_size(void); //size : ť�� ����ִ� ������ ������ ����Ѵ�.
int empty(void);    //empty : ť�� ����ִٸ� 1, �ƴϸ� 0
int front(void);    //front : ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1
int back(void);     //back : ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1

queue<int> q;

int main(void)
{
	int num;
	char str[6]; //���ڿ� ���� �ǹ����ִ� null���ڸ� �����ؼ� +1

	scanf("%d", &num);
	//��ɾ��� ���� ��ŭ
	for (int i = 0; i < num; i++)
	{
		int x;
		scanf("%s", &str);

		if (strcmp(str, "push") == 0) {
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", get_size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", front());
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", back());
		}
	}
	return 0;
}


void push(int x)
{
	q.push(x);
}

int pop(void)
{
	int temp = 0;
	if (empty())
		return -1;
	else
	{
		temp = q.front();
		q.pop();
		return temp;
	}

}

int get_size(void)
{
	return q.size();
}

int empty(void)
{
	return q.empty();
}

int front(void)
{
	if (q.empty())
		return -1;
	else
		return q.front();
}

int back(void)
{
	if (q.empty())
		return -1;
	else
		return q.back();
}
