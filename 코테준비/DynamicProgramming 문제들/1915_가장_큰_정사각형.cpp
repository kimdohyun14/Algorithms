// https://yabmoons.tistory.com/158

// ó���� ����Ž������ Ǯ���µ� �ð��ʰ��� ��!!
// ������ 1000 * 1000 * 1000�� �ϴ� 10�� => �̴� 1 ~ 2�ʷ� Ǯ �� ���ٴ� ���.
// ���̳��� ���α׷������� Ǯ��� �Ǵ� ����.
#include <iostream>
#include <string>

#define MAX 1010
using namespace std;

int N, M;
int stage[MAX][MAX];

// ���� �������<algorithm>�� �ִ� min�� ���� �ʾƵ� �̷��� ������ �����ϴ�.
int Min(int a, int b) { if (a < b) return a; return b; }

void Solution()
{
	int max_len = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (stage[i][j] != 0)
			{
				stage[i][j] = Min(stage[i - 1][j - 1], Min(stage[i - 1][j], stage[i][j - 1])) + 1;
				if (max_len < stage[i][j]) max_len = stage[i][j];
			}
		}
	}

	cout << max_len * max_len << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		// �̷��� ���ڿ��� �Է��� �޴� ��쵵 �ִ�.
		string input; cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			stage[i][j + 1] = input[j] - '0'; // char�� ���ڿ� - '0' = integer !!
		}
	}

	Solution();
	return 0;
}