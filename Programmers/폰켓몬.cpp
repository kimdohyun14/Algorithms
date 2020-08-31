#include <vector>
#include <set>
using namespace std;

// ������ ���
// ���ϸ��� ���� �ִ��� ���� N/2�̸�,
// �̿��̸� �پ��ϰ� �����Ѵ�.
// ���� 2���� ����, [3,3,3,2,2,4] ���� �ִ� ���� ���� 6/2 = 3��
// ���ϸ��� ������ 2,3,4 �̹Ƿ� �پ��ϰ� ���� �� 3���̴�. �׷��� 3�� ����
// ���� 3���� ����, [3,3,3,2,2,2] ���� �ִ� ���� ���� 6/2 = 3��
// ���ϸ��� ������ 2,3 �̹Ƿ� �پ��ϰ� ������ �� 2���̴�. �׷��� 2�� ����

int solution(vector<int> nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
        s.insert(nums[i]);
    }

    if (s.size() > nums.size() / 2)
        return nums.size() / 2;
    else
        return s.size();
}