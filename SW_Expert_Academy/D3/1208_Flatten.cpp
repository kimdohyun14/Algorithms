#include <iostream>
#include <vector>
using namespace std;

int FindMaxHeight(vector<int>& vec)
{
	int max_height = 0, idx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (max_height <= vec[i])
		{
			max_height = vec[i];
			idx = i;
		}
	}

	return idx;
}

int FindMinHeight(vector<int>& vec)
{
	int min_height = 101, idx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (min_height >= vec[i])
		{
			min_height = vec[i];
			idx = i;
		}
	}

	return idx;
}

// ��źȭ�� �� �����ؾ� �Ǵ���
bool Check(vector<int>& vec)
{
	int max_height = vec[FindMaxHeight(vec)];
	int min_height = vec[FindMinHeight(vec)];
	if ((max_height - min_height) >= 2)
		return true;

	return false;
}

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int dump;
		int max_height_idx = 0, min_height_idx = 0;
		cin >> dump;

		vector<int> heights(100);
		// ��� ������ ���̵��� ��´�.
		for (int i = 0; i < 100; i++)
			cin >> heights[i];

		for (int i = 0; i < dump; i++)
		{
			// ���� ��źȭ �۾��� ����ؾ� �Ǵ��� üũ�� ��,
			if (!Check(heights))
				break;

			// ��źȭ �۾��� �ʿ��ϸ� �Ʒ��� ���� �۾��� �����Ѵ�.
			// ���� ���� ������ ���̿� ���� ���� ������ ������ �ε����� ã�Ƽ�
			// ���� ���� ������ ���̴� 1 ����, ���� ���� ������ ���̴� 1 ����
			max_height_idx = FindMaxHeight(heights);
			min_height_idx = FindMinHeight(heights);
			heights[max_height_idx]--;
			heights[min_height_idx]++;
		}

		// ���� ���� ���� - ���� ���� ���� = ���ϴ� ��
		int answer = 0;
		max_height_idx = FindMaxHeight(heights);
		min_height_idx = FindMinHeight(heights);
		answer = heights[max_height_idx] - heights[min_height_idx];

		cout << "#" << test_case << " " << answer << endl;

	}
}