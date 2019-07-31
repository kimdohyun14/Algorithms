#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 1000000
using namespace std;

bool check[MAX_SIZE]; //�Ҽ��� �ƴ� ���� ���� (false�� �Ҽ�, true�� �Ҽ��� �ƴ� ��)

//�����佺�׳׽��� ü
void eratosthenes() {
	check[1] = true;
	for (int i = 2; i * i < MAX_SIZE; i++) {
		if (check[i] == false) {
			for (int j = i * i; j < MAX_SIZE; j += i) {
				check[j] = true;
			}
		}
	}
}

void goldBach(int n) {
	for (int i = 0, j = n; i <= n / 2; i++, j--) {
		//�� ���� Ȧ���̸鼭, ���ÿ� �Ҽ����� �Ѵ�.
		if (i % 2 == 1 && j % 2 == 1 && !check[i] && !check[j]) {
			printf("%d = %d + %d\n", n, i, j);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
}

int main() {
	eratosthenes(); //100�������� �� �߿��� �Ҽ��� ã�´�.

	while (true) { //������ �ذ��Ѵ�.
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		goldBach(n);
	}
	return 0;
}
