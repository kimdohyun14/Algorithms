#include <iostream>
#include <vector>
using namespace std;

// 2���� �迭�� �ð�������� 90�� ȸ���ϱ�
vector<vector<int> > rotateRight(vector<vector<int> >& a)
{
	int n = a.size();    // ���� ����
	int m = a[0].size(); // ���� ����
	vector<vector<int> > ret(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret[j][n - 1 - i] = a[i][j];
		}
	}
	return ret;
}
// 2���� �迭�� �ݽð�������� 90�� ȸ���ϱ�
vector<vector<int> > rotateLeft(vector<vector<int> >& a)
{
	int n = a.size();
	int m = a[0].size();
	vector<vector<int> > ret(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret[n - 1 - j][i] = a[i][j];
		}
	}
	return ret;
}

void print(vector<vector<int> >& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> a =
	{
		{0,0,0},
		{1,0,0},
		{0,1,1}
	};

	print(a);
	for (int i = 0; i < 3; i++)
	{
		a = rotateRight(a);
		print(a);
	}

	for (int i = 0; i < 3; i++)
	{
		a = rotateLeft(a);
		print(a);
	}

	return 0;
}