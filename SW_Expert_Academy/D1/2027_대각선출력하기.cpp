#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	for (int i = 0; i < 5; ++i)
	{
		// left +
		for (int j = 0; j < i; ++j)
			cout << "+";

		// middle #
		cout << "#";

		// right +
		for (int j = 0; j < 5 - 1 - i; ++j)
			cout << "+";

		cout << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}