#include <bits/stdc++.h>
using namespace std;

const int MX = 1000007;
int dat[2 * MX + 3];
int head = MX, tail = MX; // ����/ť�ʹ� �޸� �������ε� Ȯ��Ǳ� ������ 0�������� �����ϴ°� �ƴ϶� �߰����� ����, ���̴� tail - head

void push_front(int val) {
	dat[--head] = val;
}

void push_back(int val) {
	dat[tail++] = val;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main() {
	push_back(10);
	push_front(20);
	cout << front() << endl;
	cout << back() << endl;
	push_back(50);
	cout << front() << endl;
	cout << back() << endl;
	cout << "length() : " << tail - head << endl;
	return 0;
}