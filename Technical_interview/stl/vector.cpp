#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int data;
}Node;

// vector
// �����迭
// ������ ��ġ�� �ִ� ���� ���� O(1)
// �ڿ��� ���Ҹ� �߰��ϴ� ������ O(1) ���һ�ȯ�м� ����

int main()
{
	// int �ڷ����� �����ϴ� �����迭
	vector<int> vec1;
	// double �ڷ����� �����ϴ� �����迭
	vector<double> vec2;
	// ����� ���� Node ����ü�� �����ϴ� �����迭
	vector<Node> vec3;
	// ������ �ʱ� ũ�⸦ 5�� ����
	vector<int> vec4(5);
	// ������ �ʱ� ũ�⸦ 5�� �����ϰ� 1�� �ʱ�ȭ
	vector<int> vec5(5, 1);
	// ũ�Ⱑ 5 * 6�� 2���� ���͸� �����ϰ� 0���� �ʱ�ȭ
	vector<vector<int>> vec6(5, vector<int>(6, 0));
	for (int i = 0; i < vec6.size(); i++)
	{
		for (int j = 0; j < vec6[i].size(); j++)
		{
			cout << vec6[i][j];
		}
		cout << '\n';
	}

	// ������ �� �ڿ� ���� 5�� �߰�
	vec1.push_back(5);
	// ������ �� �� ���� ����
	vec1.pop_back();
	// ������ ũ�� ���
	cout << vec1.size() << '\n';
	// ������ ũ�⸦ 10���� �缳��
	vec1.resize(10);
	// ������ ��� ���� ����
	vec1.clear();
	// ������ ù ������ �ּ�, ������ ������ ���� �ּ� ����
	vec1.begin();
	vec1.end();
	// [a,b) �ּ� ������ �ش��ϴ� ���� ����
	vec1.erase(vec1.begin(), vec1.end());
	// vec7�� vec1�� 2��° ���Һ��� ������ ���ұ��� �����Ͽ� ����
	vector<int> vec7 = vector<int>(vec1.begin() + 2, vec1.end());
	return 0;
}