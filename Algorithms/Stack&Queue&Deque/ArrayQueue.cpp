#include <bits/stdc++.h>
using namespace std;

const int MX = 10000007;
int dat[MX];
int head, tail; // tail-head : ť�� ����

void push(int val) {
	dat[tail++] = val;
}

// head == tail�� �� �ش� ������ �������� �ʵ���
void pop() {
	head++;
}

// head == tail�� �� �ش� ������ �������� �ʵ���
int front() {
	return dat[head];
}

// head == tail�� �� �ش� ������ �������� �ʵ���
int back() {
	return dat[tail - 1];
}

int main() {
	push(10);
	push(20);
	push(30);
	cout << front() << endl;
	pop();
	cout << front() << endl;
	cout << back() << endl;
	pop();
	cout << front() << endl;
	cout << back() << endl;
	return 0;
}