#include <iostream>
#include <algorithm>
using namespace std;

// �����͸� ��� �����ϴ� ���
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	// ���� ������ '������ ���� ����'
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main() {
	Student students[] = {
		Student("�赵��", 90),
		Student("�ڼ���", 70),
		Student("���ѿ�", 35),
		Student("�ڴټ�", 75),
		Student("�Ѵ���", 99)
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
	return 0;
}