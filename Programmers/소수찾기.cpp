#include <string>
#include <vector>

using namespace std;

bool prime[1000001];

// �Ҽ��� �뷮���� ������ ��Ȯ�ϰ� ���ϴ� �˰���
int Eratosthenes(int n)
{
    // 1�� �Ҽ��� �ƴ�.
    prime[1] = true;

    for (int i = 2; i <= n; ++i)
    {
        if (prime[i] == false)
        {
            // �� ���� ������� ��� �����.
            for (int j = i + i; j <= n; j += i)
                prime[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (prime[i] == false)
            ++cnt;
    }

    return cnt;
}

int solution(int n) {
    int answer = Eratosthenes(n);
    return answer;
}