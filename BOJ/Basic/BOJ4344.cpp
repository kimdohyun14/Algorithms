#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;

	int student_number; // �л���
	int average;        // ��� ����
	int pass_student_number; // ��� �������� ���� �л�
	float answer;
	for (int test_case = 0; test_case < tc; test_case++) {
		cin >> student_number;
		average = 0, pass_student_number = 0;
		answer = 0;
		
		vector<int> points(student_number);
		for (int i = 0; i < student_number; i++) {
			cin >> points[i];
			average += points[i];
		}
		// ��� ����
		average = (int)(average / student_number);
		// ��� �������� ���� ����� ��
		for (int i = 0; i < student_number; i++) {
			if (average < points[i])
				pass_student_number++;
		}
		// �� (�Ҽ� ��° �ڸ����� ���, �� �ݿø�)
		answer = ((double)pass_student_number / student_number) * 100;
		cout.precision(3);
		cout << fixed << answer << "%" << '\n';
	}
}