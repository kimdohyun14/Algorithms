#include <iostream>
using namespace std;

/* �Լ� ��ü�� ����
   
   �Լ�ó�� �����ϴ� ��ü
   �ٸ� ��� ������ ��� �Լ��� ���� �� �ִ�.
   �Լ� ��ü�� ������ ������ ��ü Ÿ���� �ٸ��� ���� ���� �ٸ� Ÿ������ �ν�
   �ӵ��� �Ϲ� �Լ����� �Լ� ��ü�� �� ������.
   �Լ� ��ü�� �ζ��ε� �� �ְ�, �����Ϸ��� ���� ����ȭ�� �� �ִ�.
*/


// ��� ������ ���� �Լ� ��ü
class Adder
{
	int total;
public:
	explicit Adder(int n = 0) : total(n){}
	int operator()(int n) // �Լ� ��ü
	{
		return total += n;
	}
};

int main()
{
	Adder add(0); // �ʱ갪 0
	
	cout << add(10) << endl;
	cout << add(20) << endl;
	cout << add(30) << endl;
	cout << add(30.3) << endl;
	return 0;
}