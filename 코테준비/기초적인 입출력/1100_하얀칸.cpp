#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	// C��Ÿ�Ͽ��� 2���� �迭�� ���ڿ� �ޱ�
	// �׻� ���ڿ��� ���� �ǹ��ϴ� NULL���ڱ��� ũ�⸦ ����ؼ� ����ش�.
	char a[8][9];
	for (int i = 0; i < 8; i++)
		scanf("%s", a[i]);
	
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0 && a[i][j] == 'F')
				ans++;
		}
	}

	printf("%d", ans);
	return 0;
}