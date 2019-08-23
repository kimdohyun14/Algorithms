#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;

	stack<char> stk;
	int iron = 0, ans = 0;
	for (int i = 1; i < a.size(); ++i) {

		if (a[i - 1] == '(') {
			if (a[i] == '(') {
				stk.push(++iron); //�踷��� �߰� �� ���ÿ� Ǫ��
			}
			else if (!stk.empty() && a[i] == ')') {
				ans += stk.size();
			}
		}
		else {
			if (!stk.empty() && a[i] == ')') {
				ans += 1;
				--iron;
				stk.pop();
			}
		}
	}
	cout << ans;
	return 0;
}
