#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	// ���̸� 2��� �÷��� '����'�� ���� ���·� ����
	int length = weak.size();
	for (int i = 0; i < length; i++) {
		weak.push_back(weak[i] + n);
	}
	// ������ ģ�� ���� �ּڰ��� ã�ƾ� �ϹǷ� len(dist) + 1�� �ʱ�ȭ
	int answer = dist.size() + 1;
	// 0���� length - 1������ ��ġ�� ���� ���������� ����
	for (int start = 0; start < length; start++) {
		// ģ���� �����ϴ� ��� ��� ������ ���Ͽ� Ȯ��
		do {
			int cnt = 1; // ������ ģ���� ��
			// �ش� ģ���� ������ �� �ִ� ������ ��ġ
			int position = weak[start] + dist[cnt - 1];
			// ������������ ��� ����� ������ Ȯ��
			for (int index = start; index < start + length; index++) {
				// ������ �� �ִ� ��ġ�� ����� ���
				if (position < weak[index]) {
					cnt += 1; // ���ο� ģ�� ����
					if (cnt > dist.size()) break; // �� ������ �Ұ����ϴٸ� ����
					// �ش� ģ���� ������ �� �ִ� ������ ��ġ�� �ٽ� ����
					position = weak[index] + dist[cnt - 1];
				}
			}
			answer = min(answer, cnt); // �ּڰ� ���
		} while (next_permutation(dist.begin(), dist.end()));
	}
	return (answer > dist.size()) ? -1 : answer;
}