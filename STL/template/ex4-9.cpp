/* �Լ� ���ø� Ư��ȭ(Function Template Specialization 

   Ư��ȭ�� ������ �Լ� ���ø��� �� �����ϴ� ��   
*/
#include <iostream>
using namespace std;

class Point
{
	int x; int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
	void Print() const { cout << x << ',' << y << endl; }
};

// �Ϲ�ȭ �Լ� ���ø�
template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// Ư��ȭ �Լ� ���ø�
template<>
void Print(Point a)
{
	cout << "Print Ư��ȭ ����: ";
	a.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);  // Print<int>(n) �Ϲ�ȭ ���� ȣ��
	Print(d);  // Print<double>(d) �Ϲ�ȭ ���� ȣ��
	Print(pt); // Print<Point>(pt) Ư��ȭ ���� ȣ��

	return 0;
}