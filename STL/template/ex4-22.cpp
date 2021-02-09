/* ��ȯ Ÿ�԰� �Ű����� Ÿ���� ���ڷ� ���� �Լ� ��ü */
#include <iostream>
#include <string>
using namespace std;

template<typename RetType, typename ArgType>
class Functor
{
public:
	RetType operator()(ArgType data)
	{
		cout << data << endl;
		return RetType();
	}
};

int main()
{
	// void ��ȯ Ÿ�԰� int �Ű����� Ÿ���� ���� �Լ� ��ü
	Functor<void, int> functor1;
	functor1(10);

	// bool ��ȯ Ÿ�԰� string �Ű����� Ÿ���� ���� �Լ� ��ü
	Functor<bool, string> functor2;
	functor2("Hello!");

	return 0;
}