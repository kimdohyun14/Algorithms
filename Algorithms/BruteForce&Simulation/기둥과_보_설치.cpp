#include <bits/stdc++.h>
using namespace std;

// ������ �־��� ��� �ùķ��̼��� �ϸ� �Ǵ� ����
// ��հ� ���� ��ġ�ϰų� ������ ��, ������ ��հ� ���� ������ �����ϴ��� ��Ȯ�ϰ� Ȯ���ؾ� �Ѵ�.

// ���� ��ġ�� �������� '������' ���������� Ȯ���ϴ� �Լ�
bool possible(const vector<vector<int>>& answer) {
	for (int i = 0; i < answer.size(); i++) {
		int x = answer[i][0];
		int y = answer[i][1];
		int stuff = answer[i][2];
		if (stuff == 0) { // ��ġ�� ���� '���'�� ���
			bool check = false;
			// '�ٴ� ��'��� ����
			if (y == 0) check = true;
			// '���� �� �� �� �κ� ��' Ȥ�� '�ٸ� ��� ��'��� ����
			for (int j = 0; j < answer.size(); j++) {
				// ���� �� �� �� �κ� ��?
				if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					check = true;
				}
				// ���� �� �� �� �κ� ��?
				if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					check = true;
				}
				// �ٸ� ��� ��?
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
			}
			if (!check) return false; // �ƴ϶�� ������ ��ȯ
		}
		else if (stuff == 1) { // ��ġ�� ���� '��'�� ���
			bool check = false;
			bool left = false;
			bool right = false;
			// '���� ���κ��� ��� ��' Ȥ�� '���� ���κ��� �ٸ� ���� ���ÿ� ����'�̶�� ����
			for (int j = 0; j < answer.size(); j++) {
				// ���� ���κ��� ��� ��?
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
				// ���� ���κ��� ��� ��?
				if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
				// ������ ������?
				if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					left = true;
				}
				// �������� ������?
				if (x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					right = true;
				}
			}
			if (left && right) check = true;
			if (!check) return false; // �ƴ϶�� ���� ��ȯ
		}
	}
	return true;
}

// �ð� ���⵵ O(N^3)
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	// �۾��� ������ �ִ� 1,000�� [x,y,a,b] ����
	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];          
		int stuff = build_frame[i][2];    // ������ ����
		int operate = build_frame[i][3];
		if (operate == 0) { // �����ϴ� ���
			// �ϴ� ������ �� �� �ڿ�
			int index = 0;
			// [x,y,a] ����
			for (int j = 0; j < answer.size(); j++) {
				if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]) {
					index = j;
				}
			}
			vector<int> erased = answer[index];
			answer.erase(answer.begin() + index);
			if (!possible(answer)) { // ������ ���������� Ȯ��
				answer.push_back(erased); // ������ �������� �ƴ϶�� �ٽ� ��ġ
			}
		}
		if (operate == 1) { // ��ġ�ϴ� ���
			// �ϴ� ��ġ�� �� �� �ڿ�
			vector<int> inserted;
			inserted.push_back(x);
			inserted.push_back(y);
			inserted.push_back(stuff);
			answer.push_back(inserted);
			if (!possible(answer)) { // ������ ���������� Ȯ��
				answer.pop_back(); // ������ �������� �ƴ϶�� �ٽ� ����
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}