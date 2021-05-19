#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> vec(n, 1);

	// ������ ü������ ������ ������ +1 ����
	for (int i = 0; i < reserve.size(); ++i) {
		int idx = reserve[i] - 1;
		++vec[idx];
	}

	// �������� �л��� ü���� -1 ����
	for (int i = 0; i < lost.size(); ++i) {
		int idx = lost[i] - 1;
		--vec[idx];
	}

	// ��ü �л��� ���캸�鼭, �ش� �л��� ü������ ���ٸ�?
	// ���� �л��� ���� �л� �߿��� �� ���� ü������ ������ �ִٸ�, �� ������� ������.
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == 0) {
			if (vec[i - 1] >= 2 && i >= 0) {
				--vec[i - 1];
				++vec[i];
			}

			else if (vec[i + 1] >= 2 && i + 1 < n) {
				--vec[i + 1];
				++vec[i];
			}
		}
	}

	// ��ü �л��� ���캸�鼭, �ش� �л��� ü������ ������ �ִٸ� ���� ī��Ʈ
	for (int i = 0; i < vec.size(); ++i)
		if (vec[i]) ++answer;

	return answer;

}