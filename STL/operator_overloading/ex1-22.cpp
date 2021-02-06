#include <iostream>
using namespace std;

/* (* ������ �����ε�) */

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
};

class PointPtr
{
	Point* ptr;
public:
	PointPtr(Point* p) : ptr(p) {}
	~PointPtr()
	{
		delete ptr;
	}

	Point* operator->()const
	{
		return ptr;
	}

	Point& operator*()const
	{
		return *ptr;
	}
};

int main()
{
	Point* p1 = new Point(2, 3);   // �Ϲ� ������
	PointPtr p2 = new Point(5, 5); // ����Ʈ ������

	p1->Print(); // p1->Print()
	p2->Print(); // p2.operator->()->Print()
	cout << endl;

	/* p1�� �Ϲ� �������̰�, *p1�� ��ü ��ü�̹Ƿ� ��� �Լ��� ȣ���Ѵ�. 
	   p2�� ����Ʈ �����ͷ�, *p2�� ��ü�� ��ȯ�ϰ� p2.operator*()�� ȣ���ϰ�
	   ��ü ������ ��ȯ�޾� ��� �Լ��� ȣ���Ѵ�. */
	(*p1).Print();
	(*p2).Print(); // p2.operator*().Print()

	delete p1;
	// p2�� �Ҹ��ڿ��� Point ���� ��ü�� �ڵ����� �޸𸮿��� �����Ѵ�
	return 0;
}