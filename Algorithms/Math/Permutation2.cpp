#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;
bool visited[8];
int ans;
// 8���� ���ڸ� ������ �̾ƺ���
void Recursive(int cnt)
{
	if (cnt == 8)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 8; ++i)
	{
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(i);
		Recursive(cnt + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main()
{
	Recursive(0);
	cout << ans << endl;
	return 0;
}