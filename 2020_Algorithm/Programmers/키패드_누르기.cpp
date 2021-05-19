#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

struct pos
{
    int x;
    int y;
};

void setPos(unordered_map<int, pos>& m)
{
    int key = 0;
    m[key++] = { 3, 1 };
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m[key++] = { i, j };
        }
    }
}

string solution(vector<int> numbers, string hand) {

    // [key : 번호 , value : position]
    unordered_map<int, pos> mp;

    // 0 ~ 9까지의 숫자 위치맵 생성
    setPos(mp);

    pos leftHand = { 3, 0 };
    pos rightHand = { 3, 2 };
    string answer = "";

    for (int i = 0; i < numbers.size(); ++i)
    {
        int num = numbers[i];
        // 왼쪽 손
        if (num == 1 || num == 4 || num == 7)
        {
            leftHand = mp[num];
            answer += 'L';
        }
        // 오른쪽 손
        else if (num == 3 || num == 6 || num == 9)
        {
            rightHand = mp[num];
            answer += 'R';
        }
        // 중간
        else
        {
            // 거리는 A와 B의 각 좌표들을 빼주고 그런 다음에, 각각을 절대값을 씌운뒤에 더하면 구할 수 있다.
            pos mid = mp[num];
            int leftDiff = abs(mid.x - leftHand.x) + abs(mid.y - leftHand.y);
            int rightDiff = abs(mid.x - rightHand.x) + abs(mid.y - rightHand.y);

            if (leftDiff == rightDiff)
            {
                if (hand == "left")
                {
                    leftHand = mid;
                    answer += 'L';
                }

                else
                {
                    rightHand = mid;
                    answer += 'R';
                }
            }

            else if (leftDiff < rightDiff)
            {
                leftHand = mid;
                answer += 'L';
            }

            else
            {
                rightHand = mid;
                answer += 'R';
            }
        }
    }

    return answer;
}
