#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    // ó������ k �̻��� ���� �����ϴ� ��ġ
    cout << lower_bound(v.begin(), v.end(), k) - v.begin() + 1 << endl;
    return 0;
}