#include <iostream>
#include <cstdlib>
#include <vector>
#define MAX_SIZE 105
using namespace std;

vector<int> mp[MAX_SIZE];
bool visit[MAX_SIZE];

//����ư �Ÿ� ���
int diffStreet(vector<pair<int, int>> street, int u, int v) {
	return abs(street[u].first - street[v].first) + abs(street[u].second - street[v].second);
}

//dfsŽ���ϸ鼭 �湮�� �Ѵ�.
void runStreet(int node) {
	visit[node] = true;
	for (int i = 0; i < mp[node].size(); i++) {
		int nextNode = mp[node][i];
		if (visit[nextNode] == false) {
			runStreet(nextNode);
		}
	}
}

bool solve(vector<pair<int, int>> street, int size) {
	//A�������� B�������� �� ��, �ִ�� �� �� �ִ� ��δ� 1000����
	//���� 1000�̳��� ��� ������ ������ ǥ���Ѵ�.
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int range = diffStreet(street, i, j);
			if (range <= 1000) { //A������ B������ 1000�Ÿ� �̳��̸� ���� �� �� �ִ� ����.
				mp[i].push_back(j);
				mp[j].push_back(i);
			}
		}
	}

	runStreet(0); //����������� ����
	if (visit[size - 1] == false) { //������������
		return false;
	}
	else { //�ߴٸ�
		return true;
	}
}

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		visit[i] = false;
		mp[i].clear();
	}
}

int main() {
	int t;
	cin >> t;
	for (int testCase = 1; testCase <= t; testCase++) {
		init();       //�ʱ�ȭ
		int area = 2; //������� + �佺Ƽ��
		int shop;     //������ ��
		cin >> shop;
		area += shop;
		vector<pair<int, int>> street(MAX_SIZE);
		for (int i = 0; i < area; i++) { //(x, y)��ǥ
			cin >> street[i].first >> street[i].second;
		}

		bool ret = solve(street, area);
		if (ret == false)
			cout << "sad" << '\n';
		else
			cout << "happy" << '\n';
	}
	return 0;
}