#include <iostream>
#define MAX 15
using namespace std;

int k, n, t;
int arr[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	// 0�� 1ȣ ~ 14ȣ ä���ֱ�
	for (int i = 1; i < MAX; i++) {
		arr[0][i] = i;
	}

	// 1�� ~ 14������ �� 1ȣ ~ 14ȣ ä���ֱ�
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			int sum = 0;
			for (int k = 1; k <= j; k++) {
				sum += arr[i - 1][k];
			}
			arr[i][j] = sum;
		}
	}

	while (t--) {
		cin >> k >> n;
		cout << arr[k][n] << '\n';
	}

	return 0;
}