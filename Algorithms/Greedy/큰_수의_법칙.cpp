#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int first = v[N - 1]; // ���� ū ��
	int second = v[N - 2];// �� ��°�� ū ��

	// ���� ū ���� �������� Ƚ�� ���
	int cnt = (M / (K + 1)) * K;
	cnt += M % (K + 1);

	int result = 0;
	result += cnt * first; // ���� ū �� ���ϱ�
	result += (M - cnt) * second; // �� ��°�� ū �� ���ϱ�
	
	cout << result << '\n';
	return 0;
}