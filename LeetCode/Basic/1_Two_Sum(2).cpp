class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        �ؽ��� ���, ���� 1���� ���鼭 �̹� �ô� ���� �ؽ��ʿ� �ִ´�.
            - �ð�: O(N)
            - ����: O(N)
        */
        unordered_map<int, int> hash; // Ű-��, ����-�ε���
        vector<int> answer(2);

        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            if (hash.find(target - cur) != hash.end())
            {
                answer[0] = i;
                answer[1] = hash[target - cur];
                return answer;
            }
            else
            {
                hash.insert({ cur, i });
            }
        }

        return answer;
    }
};