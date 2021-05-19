#include <iostream>
#include <stack>
using namespace std;

int n, h;
long long ans;
stack<int> s;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    // �ڽ��� �� �� �ִ� �Ұ� �� �������� �ľ��ϴ� ��
    // stack�� ����ϸ� O(N)���� �ذᰡ��
    // s.pop() �� s.push() �� O(1)�̱� ����
    for (int i = 0; i < n; i++)
    {
        cin >> h;

        while (!s.empty() && s.top() <= h) s.pop();
        s.push(h);
        if (s.size() >= 1) ans += s.size() - 1;
    }

    cout << ans << '\n';
    return 0;
}