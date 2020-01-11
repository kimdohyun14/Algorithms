#include <iostream>
#include <vector>
using namespace std;

int calculator(int n) {
	//Tn = n(n+1)/2
	int sum = n * (n + 1) / 2;
	return sum;
}

bool solve(const vector<int> &a, int sum) {
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 45; j++) {
			for (int k = 0; k < 45; k++) {
				if (sum == (a[i] + a[j] + a[k])) 
					return true;
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	vector<int> a(45, 0);
	for (int i = 0; i < 45; i++) { //45���� �ﰢ���� ���س���
		a[i] = calculator(i + 1);
	}

	for (int testCase = 1; testCase <= t; testCase++) {
		int sum;
		cin >> sum;
		if (solve(a, sum)) //������ Ǭ��.
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}