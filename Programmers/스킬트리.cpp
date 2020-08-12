#include <string>
#include <vector>
#include <iostream>
using namespace std;

// origin�� str�� ��, �ϳ��� Ʋ���� false �ƴϸ� true
bool matching(string origin, string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (origin[i] != str[i])
            return false;
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    vector<string> v;
    // �־��� �迭���� �ش� ���ڿ��� skill�� ���ڰ� ���� �͸� ��󳽴�.
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        string str = skill_trees[i];
        string make = "";
        for (int j = 0; j < str.size(); ++j)
        {
            for (int k = 0; k < skill.size(); ++k)
            {
                if (str[j] == skill[k])
                {
                    make += str[j];
                    break;
                }
            }
        }
        v.push_back(make);
    }

    for (int i = 0; i < v.size(); ++i)
    {
        // ���ེų�� ���ٴ� �ǹ�
        if (v[i] == "")
            ++answer;
        else
        {
            // ���ེų�� ����ִٸ� ���غ���.
            if (matching(skill, v[i]))
                ++answer;
        }
    }

    return answer;
}