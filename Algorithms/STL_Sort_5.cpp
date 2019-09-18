#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	// ������ �����ϴٸ� ���̰� �� � �л��� �� ����
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else { // ������ ���� �������
		return a.second.first > b.second.first;
	}
}

int main() {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("�赵��", pair<int, int>(90, 19950208)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(87, 19980411)));
	v.push_back(pair<string, pair<int, int>>("���ѿ�", pair<int, int>(59, 19970218)));
	v.push_back(pair<string, pair<int, int>>("�̻��", pair<int, int>(93, 19930508)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(90, 19960411)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}