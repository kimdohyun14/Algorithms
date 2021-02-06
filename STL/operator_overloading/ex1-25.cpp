#include <iostream>
using namespace std;

/* �����ڸ� �̿��� ����ȯ�� �ǵ����� �ʴ´ٸ�
   �����ڴ� ����� ȣ�⸸ �����ϵ��� �ϴ� explicit Ű���带 �̿�����. */

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
	void Print() const { cout << x << ',' << y << endl; }
};

int main()
{
	Point pt;
	pt.Print();

	// pt = 10; �Ͻ��� ������ ȣ���� �Ұ����ϴ�.
	pt = Point(10); // ����� ������ ȣ�⸸ �����ϴ�.
	pt.Print();
	return 0;
}