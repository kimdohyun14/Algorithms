#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int>& v) {

	int maxValue = *max_element(v.begin(), v.end());

	// �� �ڸ����� ���� ����
	for (int digit = 1; digit <= maxValue; digit *= 10) {
		vector<int> output(v.size());
		vector<int> bucket(10, 0);

		cout << digit << "�ڸ���\n";
		// �� �ڸ����� ��Ŷ�� ����
		for (int i = 0; i < v.size(); i++) {
			bucket[(v[i] / digit) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}
		// �ڸ����� ���� ���� ���� ���� ������ ���� �ڿ������� ����
		for (int i = v.size() - 1; i > -1; i--) {
			int k = (v[i] / digit) % 10;
			output[bucket[k] - 1] = v[i];
			bucket[k]--;
		}
		for (int i = 0; i < v.size(); i++) {
			v[i] = output[i];
		}
	}
}

int main() {
	vector<int> arr = { 152,73,69,41,28,1247,2,33,674,388 };
	radixSort(arr);
	for (auto n : arr) {
		cout << n << ' ';
	}
	return 0;
}